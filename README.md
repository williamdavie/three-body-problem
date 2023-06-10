
<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/banner.png" width="80%" height="20%">

# Three-Body-Problem

A graphical simulation of the three body problem written in C++. This project is my first C++ project, it uses the fourth order Runge-Kutta numerical method to solve an ordinary differential equation to describe the motion of three particles. The project aimed to represent this problem using fancy OpenGl graphics. 

#### Libraries ####                                                   
- [GLFW](https://www.glfw.org/docs/latest/)
- [Eigen](https://eigen.tuxfamily.org/index.php?title=Main_Page)

#### References ####

- [Equations of Motion](https://en.wikipedia.org/wiki/Three-body_problem)
- [Runge Kutta](http://numerical.recipes/)
- [Initial Conditions](https://sites.math.washington.edu/~morrow/336_12/papers/adrian.pdf)



## Physics

The motion of the bodies included in the three body problem is described entirely by Newtons law of gravitation:

<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/EquationOne.png" width="40%" height="40%">

However, the 'problem' arises in choosing the inital conditions required to set the bodies into a 'stable' motion, the majority of states are extremely unstable ( When we slightly change initial conditions, the trajectory of each body changes dramatically). Solutions to this problem include the Euler, Lagrange and figure-of-eight solutions and can be understood in great detail using the 'Inital Conditions' reference. Two examples are given below

### Lagrange solution          
<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/Lagrange.gif" width="40%" height="40%"> 

### Choatic Example

<img src="https://github.com/DrDavie1/Three-Body-Problem/blob/main/Media/Lagrange.gif" width="40%" height="40%">






