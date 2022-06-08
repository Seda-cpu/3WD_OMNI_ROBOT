#include "ros.h"
#include "geometry_msgs/Twist.h"


int motor_left_pin1 = 4;
int motor_left_pin2 = 5;
int motor_left_speed = 10;
int motor_right_pin1 = 6;
int motor_right_pin2 = 7;
int motor_right_speed = 11;
int motor_back_pin1 = 8;
int motor_back_pin2 = 9;
int motor_back_speed = 12;

ros::NodeHandle nh;

void velCallback( const geometry_msgs::Twist& vel){

  //ileri
  if(vel.linear.x >0){
    //ileri git.
    analogWrite(motor_left_speed, vel.linear.x*100);
    analogWrite(motor_right_speed, vel.linear.x*100);
    digitalWrite(motor_left_pin1, HIGH);
    digitalWrite(motor_left_pin2, LOW);
    digitalWrite(motor_right_pin1, HIGH);
    digitalWrite(motor_right_pin2, LOW);
    nh.loginfo("ileri");
    }
  else if (vel.linear.x < 0){
    //geri git.
    analogWrite(motor_left_speed, vel.linear.x*100);
    analogWrite(motor_right_speed, vel.linear.x*100);
    digitalWrite(motor_left_pin1, LOW);
    digitalWrite(motor_left_pin2, HIGH);
    digitalWrite(motor_right_pin1, LOW);
    digitalWrite(motor_right_pin2, HIGH);
    nh.loginfo("geri");
    }
  else if (vel.angular.z > 0){
    //sağa don.
    analogWrite(motor_left_speed, 255);
    analogWrite(motor_right_speed, 255);
    analogWrite(motor_back_speed, 255);
    digitalWrite(motor_left_pin1, HIGH);
    digitalWrite(motor_left_pin2, LOW);
    digitalWrite(motor_right_pin1, HIGH);
    digitalWrite(motor_right_pin2, LOW);
    digitalWrite(motor_back_pin1, HIGH);
    digitalWrite(motor_back_pin2, LOW);
    nh.loginfo("saga donus");
    }
  else if (vel.angular.z < 0){
    //sola don.
    analogWrite(motor_left_speed, 255);
    analogWrite(motor_right_speed, 255);
    analogWrite(motor_back_speed, 255);
    digitalWrite(motor_left_pin1, LOW);
    digitalWrite(motor_left_pin2, HIGH);
    digitalWrite(motor_right_pin1, LOW);
    digitalWrite(motor_right_pin2, HIGH);
    digitalWrite(motor_back_pin1, LOW);
    digitalWrite(motor_back_pin2, HIGH);
    nh.loginfo("sola donus");
    }
  else if (vel.linear.x == 0 and vel.angular.z == 0){
    //dur
    analogWrite(motor_left_speed, 0);
    analogWrite(motor_right_speed, 0);
    analogWrite(motor_back_speed, 0);
    nh.loginfo("dur");
    }  
  }

ros::Subscriber<geometry_msgs::Twist>sub("cmd_vel", velCallback);


void setup() {
  // put your setup code here, to run once:
  nh.initNode();
  nh.subscribe(sub);

  pinMode(motor_left_pin1, OUTPUT);
  pinMode(motor_left_pin2, OUTPUT);
  pinMode(motor_left_speed, OUTPUT);
  pinMode(motor_right_pin1, OUTPUT);
  pinMode(motor_right_pin2, OUTPUT);
  pinMode(motor_right_speed, OUTPUT);
  pinMode(motor_back_pin1, OUTPUT);
  pinMode(motor_back_pin2, OUTPUT);
  pinMode(motor_back_speed, OUTPUT);
  
}
//
void loop() {
  // put your main code here, to run repeatedly:

  nh.spinOnce();

}
