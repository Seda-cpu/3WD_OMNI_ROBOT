#include "ros.h"
#include "geometry_msgs/Twist.h"

ros::NodeHandle nh;

float x;

void velCallback(const geometry_msgs::Twist& vel){
  
    if (vel.linear.x > 1.0){
        digitalWrite(13, HIGH);
        nh.loginfo("led yandı");        
      }
    else if (vel.linear.x < 1.0){
        digitalWrite(13, LOW);
        nh.loginfo("led sondu");
        
      }
  }

ros::Subscriber<geometry_msgs::Twist> sub("cmd_vel", velCallback);

void setup() {
  // put your setup code here, to run once:
  pinMode(13, OUTPUT);
  nh.initNode();
  nh.subscribe(sub);
}

void loop() {
  // put your main code here, to run repeatedly:
  nh.spinOnce();
  delay(10);

}
