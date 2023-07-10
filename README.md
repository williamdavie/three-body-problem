
<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/banner.png" width="80%" height="20%">

# Three Body Problem

A graphical simulation of the three body problem written in C++. This project is my first C++ project, it uses the fourth order Runge-Kutta numerical method to solve an ordinary differential equation to describe the motion of three particles. The project aimed to represent this problem using fancy OpenGl graphics. See bottom of Readme for running information.

#### Libraries ####                                                   
- [GLFW](https://www.glfw.org/docs/latest/)
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

#### References ####

- [Equations of Motion](https://en.wikipedia.org/wiki/Three-body_problem)
- [Runge Kutta](http://numerical.recipes/)
- [Initial Conditions](https://www.maths.ed.ac.uk/~ateckent/vacation_reports/Report_Faustino.pdf)



## Physics

The motion of the bodies included in the three body problem is described entirely by Newtons law of gravitation:

<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/EquationOne.png" width="40%" height="40%">

However, the 'problem' arises in choosing the inital conditions required to set the bodies into a 'stable' motion, the majority of states are extremely unstable ( When we slightly change initial conditions, the trajectory of each body changes dramatically). Solutions to this problem include the Euler, Lagrange and figure-of-eight solutions and can be understood in great detail using the 'Inital Conditions' reference. Two examples are given below

## Lagrange solution    
<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/Lagrange.gif" width="40%" height="40%"> 

## Choatic Example
<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/ChaosTheory.gif" width="60%" height="100%">

# Running Information

Running this program is relatively simple, once you have relevant libraries installed. 

I used Apples xcode. To compile the project this way create a 'Command Line Tool' project template and copy the project into this template. 

Then include the relevant graphics library following this youtube video:

- [GLFW Apple Silicon](https://www.youtube.com/watch?v=MHlbNbWlrIM)

Once the library is installed, include eigen which can be installed via:
```
brew install eigen
```
and can easily be added to an xcode project via; Build Settings -> Header Search Paths, once complete you should be able to compile the project. 

If you are using Windows I'd recommend following Youtube or GLFW docs and use your usual cpp editor. 







