# 3WD_OMNI_ROBOT

In this project I made SLAM with 3WD Onidirectional Robot. The mobile robot chasis consists of 3 omni wheels spaced at 120 degrees apart. It is designed for indoor mapping by keeping maneuverability in the first place.
You can find the chasis in this link: https://www.nexusrobot.com/product/3wd-48mm-omni-wheel-robot-platform-chassiswith-encoderblack-15001b.html


For mapping, Hector SLAM and GMapping methods have been tried and compared.
Another unique aspect of the work is that it can be controlled via the WEB interface that I designed.

For seeing and controlling manually on gazebo with teleop_twist_keyboard you can launch gazebo.launch
```ruby
roslaunch diff gazebo.launch
```
This is differential drive for controlling with teleop_twist_keyboard. I made omnidirectional drive in arduino code for controlling the real robot. You can check the 1.ino code in arduino folder.
![Screenshot from 2022-07-12 21-08-39](https://user-images.githubusercontent.com/74606830/178563109-c2e8e62e-2823-4b6e-afdf-ad345e6d91a9.png)


for seeing in RVIZ:
```ruby
roslaunch diff rviz.launch
```
![Screenshot from 2022-07-12 21-13-45](https://user-images.githubusercontent.com/74606830/178565063-1f780ccb-dd4d-4c28-a404-c01b1e4f0e97.png)

 * Wheels model from here: https://github.com/GuiRitter/OpenBase

# ROBOT KINEMATICS

![kinematiik_analiz-Page-1 drawio](https://user-images.githubusercontent.com/74606830/178559020-290b9f84-4dd1-4643-b7a1-a13257a1a530.png)

![0](https://user-images.githubusercontent.com/74606830/178559258-94dfe103-12a5-4e8d-9d00-13d5b7112dc8.png)
![0](https://user-images.githubusercontent.com/74606830/178559350-2d6548e0-0939-41a9-9763-3a17bacbbce4.png)
![1](https://user-images.githubusercontent.com/74606830/178559474-562ad593-2ce1-4ab7-be49-52975bec436f.png)

# SLAM (simultaneous localization and mapping)

*The robot needs to map of its enviroment to determine the position and to know their own location to map the enviroment.*

GMAPPING

For Gmapping, you only launch this gmapping.launch file and use the teleop_twist for kontrolling and mapping.

```ruby
roslaunch diff gmapping.launch
```
https://www.youtube.com/watch?v=kkTh4ROfFig&t=1s

HECTOR

For hector SLAM:

```ruby
roslaunch diff gazebo.launch
```
```ruby
 roslaunch hector_slam_launch tutorial.launch 
```
```ruby
rosrun teleop_twist_keyboard teleop_twist_keyboard
```

https://www.youtube.com/watch?v=_wcQZBHmdKQ&t=4s

* Here is the real robot
![0](https://user-images.githubusercontent.com/74606830/178567926-40184dff-ba53-447d-88e9-74caa29f06ed.png)

When we control the real robot first we need to activate RPLidar.
```ruby
ls -l /dev |grep ttyUSB
```
```ruby
sudo chmod 666 /dev/ttyUSB0
```
```ruby
roslaunch rplidar_ros view_rplidar.launch
```
* Then we start rosserial
```ruby
rosrun rosserial_arduino serial_node.py /dev/ttyUSB1
```
After starting the comminication between ros and arduino. You can launch the hector slam node and start to mapping.
