/**
* feed.cpp
*
* Jacob "Kobi" Tessman
*
* The cpp file for the Feed object.
*/

#include "feed.h"
#include <iostream>
#include <gtkmm/button.h>
#include <gtkmm/box.h>
#include <gtkmm/messagedialog.h>
#include <cairomm/context.h>
#include <ctime>
#include <stdio.h>
#include <string.h>


/**
* Feed
*
* input: none
*
* output: Feed object
*
* The constructor for the feed object.
*/
Feed::Feed()
{
    recording_align.add(recording);
    this->add(recording_align);
    recording_align.set(Gtk::ALIGN_RIGHT, Gtk::ALIGN_CENTER, 0.0, 0.0);
    recording.set("../record-OFF.png");
    this->add(cur_frame);
    cur_frame.set("../noCamera.png");
    recording_align.show();
    recording.show();
    cur_frame.show();
    connected = false;
    cam_ID = 0;
    width = 500;
    height = 380;
    this->set_buttons();
    default_num_gs_frames = 25; //25 frames is half a second;
    seconds_recording = 100; //4 seconds by default
    catching_frames = false;
    noise = false;
    user_email_address = "kobi.tessman@gmail.com"; //default on startup
    user_folder = "/home/kobi/Desktop/MotionVideos/"; //default on startup
}

/**
* ~Feed
*
* input: none
*
* output: none
*
* The destructor for the feed object. Since there's only four at any given time,
* we do not need to worry about freeing anything.
*/
Feed::~Feed()
{

}


/**
* refresh
*
* input: none
*
* output: bool
*
* The core functionality of the Feed object. This function is called in the
* background every 20 ms to refresh the camera frame as well as do any of the
* detection work. If the program is currently detecting, then add the frame to
* the feed object's VideoWriter. If the noise that was calculated is above
* 2000000 AND the program is detecting, then the program is now detecting. In
* order to calculate the feed, pop one gray frame off the end of the array and
* push the new gray frame on. Compare the old gray frame with the new gray frame.
* The file writing work used to be its own seperate function, but the function
* needed to be able to save the current frame with the exact same date and time
* as the video. Hence this function is longer than I'd like, but what can you
* do. Returns true or false depending on whether or not the frame got caught.
*/
bool Feed::refresh()
{
    cap.read(frame);
    //do that in a function
    //cap.open(deviceID + apiID);

    if(!frame.empty())
    {

      //Code to convert a cv::Mat object to a Gtk::Image from geeksforgeeks.
      cv::resize(frame, resized, cv::Size(width, height),
          0, 0, cv::INTER_LINEAR);
      cvtColor(resized, resized, cv::COLOR_BGR2RGB);
      auto img = Gdk::Pixbuf::create_from_data(resized.data,
                        Gdk::COLORSPACE_RGB,
                        resized.channels() == 4,
                        8,
                        width,
                        height,
                        (int)resized.step);


      cv::Mat gray_frame, comp;
      int noise = 0;
      cv::cvtColor(resized, gray_frame, CV_BGR2GRAY);
      pastframes.push(gray_frame);
      cv::absdiff(gray_frame, pastframes.front(), comp);


      if(pastframes.size() >= default_num_gs_frames)
      {
          for(int i = 0; i < comp.rows; i++)
        	{
        		for(int j = 0; j < comp.cols; j++)
        		{
        			noise += (int)comp.at<uchar>(i, j);
        		}
        	}
          pastframes.pop();
      }

      cv::Mat written_frame;
      cv::cvtColor(resized, written_frame, CV_BGR2RGB);

      if(catching_frames == true)
      {
        video.write(written_frame);
      }

      cur_frame.set(img);
      cv::waitKey();

      if(catching_frames == false && noise > 2000000)
      {

        catching_frames = true;
        recording.set("../record-ON.png");

        time_t rawtime;
        struct tm * timeinfo;
        char buffer[80];

        time (&rawtime);
        timeinfo = localtime(&rawtime);

        strftime(buffer,sizeof(buffer),"%d-%m-%Y-%H:%M:%S",timeinfo);
        std::string str(buffer);

        //potential bug here where the user might change the folder name
        //the millisecond that the in between lines 150 and 151.
        std::string video_filename = user_folder + str + ".avi";
        std::string picture_filename = user_folder + str + ".png";
        cv::imwrite(picture_filename, written_frame),
        this->email_notification(picture_filename, str);
        video = cv::VideoWriter(video_filename, CV_FOURCC('M', 'J', 'P', 'G'), 30, cv::Size(width, height));

        std::cout  << str << std::endl;


        frames_caught = seconds_recording;
      }

      if(catching_frames == true)
      {
        frames_caught--;
        if(frames_caught <= 0)
        {
          catching_frames = false;
          recording.set("../record-OFF.png");
        }
      }

      return true;


    }
    else
    {
      this->disconnect();
    }
    return false;
}

/**
* set_device_id
*
* input: int i
*
* output: none
*
* THIS FUNCTION NEEDS TO BE CALLED DIRECTLY AFTER CREATING A FEED OBJECT. Sets
* the feed's camera ID (I.E dev/video0, dev/video1...)
*/
void Feed::set_device_id(int i)
{
  cam_ID = i;
}


/**
* set mode
*
* input: none
*
* output: none
*
* What happens when the user clicks the mode button. It will switch the mode to
* and from showing the unfiltered frame, vs showing the difference in the frame
* that came 25 ms before it.
*/
void Feed::set_mode()
{
    if(noise == true)
    {
      noise = false;
    }
    else
    {
      noise = true;
    }
}

/**
* disconnect
*
* input: none
*
* output: none
*
* The function that is called whenever the user presses the "Disconnect" button
* on the feed. If the camera is connected, free it, and then set the presented
* image back accordingly.
*/
void Feed::disconnect()
{
  if(connected)
  {
    cap.release();
    connected = false;
    frames_caught = 0;
    cur_frame.set("../noCamera.png");
    signal.disconnect();
  }
}


/**
* connect
*
* input: none
*
* output: none
*
* The function that is called whenever the user presses the "Disconnect" button
* on the feed. If the camera is connected, free it, and then set the presented
* image back accordingly.
*/
void Feed::connect()
{
  frames_caught = 0;
  std::queue<cv::Mat> empty;
  std::swap(this->pastframes, empty);

  int api_ID = cv::CAP_ANY;
  cap.open(cam_ID);
  if(!connected && cap.isOpened())
  {
    connected = true;
    signal = Glib::signal_timeout().connect(
    sigc::mem_fun(*this, &Feed::refresh), 20); //1000/20 = 50 fps
  }
  else
  {
    Gtk::MessageDialog dialog("Error", false, Gtk::MESSAGE_INFO, Gtk::BUTTONS_OK, false);
    std::string message = "Could not open/dev/video/" + std::to_string(cam_ID);
    std::cout << message << std::endl;
        dialog.set_secondary_text(message);
        dialog.run();
  }

}

/**
* set_buttons
*
* input: none
*
* output: none
*
* A function that is called once during the Feed object's constructor. Sets up
* all of the buttons.
*/
void Feed::set_buttons()
{
  b_detect.set_label("Detect");
  b_forget.set_label("Forget");
  b_forget.signal_clicked().
  connect(sigc::mem_fun(*this, &Feed::disconnect));
  b_detect.signal_clicked().
  connect(sigc::mem_fun(*this, &Feed::connect));
  feed_buttons.add(b_forget);
  feed_buttons.add(b_detect);
  feed_buttons.pack_start(b_detect);
  feed_buttons.pack_start(b_forget);
  this->pack_start(feed_buttons);
  b_detect.show();
  b_forget.show();
  feed_buttons.show();
}

/**
* set_hw
*
* input: int h, int w
*
* output: none
*
* Sets up the height and width of the picture frames that are read and
* translated. Will maybe implement a button that utilizes this function in the
* future.
*/
void Feed::set_hw(int h, int w)
{
  //take in one frame and base the heigth and width off of it.
  //makes it so we don't have to do this on every iteration.
  height = h;
  width = w;

}

/**
* email_notification
*
* input: string filename, string date_and_time
*
* output: none
*
* The function that assembles the mutt command into a string from the filename
* of the file to be attached and the date and time (combined into one string)
* and then makes it run in the background on linux.
*/
void Feed::email_notification(std::string filename, std::string date_and_time)
{
  //This is horrendous, but the popen function only takes char pointers and
  //not strings.
  std::string email = "echo \"Picture of motion:\" | mutt -a \""
                     + filename
                     + "\"  -s \"LittleBrother detected motion on "
                     + date_and_time
                     + "\" -- "
                     + user_email_address
                     + " &";

  int n = email.size();
  char emailchar[n+1];

  std::strcpy(emailchar, email.c_str());
  FILE *mailpipe = popen(emailchar,"w"); //piping to command line
      pclose(mailpipe);

}

/**
* feed_change_email
*
* input: string new_email
*
* output: none
*
* A function that simply changes the email of the feed.
*/
void Feed::feed_change_email(std::string new_email)
{
  user_email_address = new_email;
}


/**
* feed_change_folder
*
* input string new_folder
*
* output: none
*
* A function that simply changes the email of the feed.
*/
void Feed::feed_change_folder(std::string new_folder)
{
  user_folder = new_folder;
}
