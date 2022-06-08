# teleop_keyboard_omni3
Generic Keyboard Teleop for 3 Wheeled Omnidirectional robots

- For package details : [ROS Wiki](http://wiki.ros.org/teleop_keyboard_omni3)

- Motion Analysis of 3 wheeled omnidirectional robot (Theory involved in writing the code): [Blog post](https://yainnoware.blogspot.com/2019/03/three-wheeled-holonomic-robot-theory.html)

- Simulated the three-wheeled robot on Gazebo to test the code. Package Link : [omni3ros_pkg](https://github.com/YugAjmera/omni3ros_pkg)

## Installation
1. `cd ~/catkin_ws/src`
2. `git clone https://github.com/YugAjmera/teleop_keyboard_omni3`
3. `cd ~/catkin_ws`
4. `catkin_make`
5. `source ~/catkin_ws/devel/setup.bash`
6. `source ~/.bashrc`

Change the topic names in this [scipt](teleop_keyboard_omni3.py) according to your robot.

## Launch
Run.
```
rosrun teleop_keyboard_omni3 teleop_keyboard_omni3.py 
```

## Usage

```
Reading from the keyboard !
---------------------------
Moving around:
   u    i    o
   j    k    l
   m    ,    .

For Holonomic mode (strafing), hold down the shift key:
---------------------------
   U    I    O
   J    K    L
   M    <    >


anything else : stop

q/z : increase/decrease max speeds by 10%

CTRL-C to quit
```


If our work is helpful to you, please kindly cite our paper as:
```
@inproceedings{mishra2019ego,
  title={Ego-Centric framework for a three-wheel omni-drive Telepresence robot},
  author={Mishra, Ruchik and Ajmera, Yug and Mishra, Nikhil and Javed, Arshad},
  booktitle={2019 IEEE International Conference on Advanced Robotics and its Social Impacts (ARSO)},
  pages={281--286},
  year={2019},
  organization={IEEE}
}
```
