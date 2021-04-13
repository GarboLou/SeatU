# SeatU
# Introduction
The school library is one of the student’s favorite places to study as it can provide them with a silent
environment. However, our team noticed that sometimes it is very difficult to find a seat in the library,
especially during exam weeks. There is a complaint about the unknown seat availability in our campus
library. Besides, some students may leave personal belongings such as books to occupy a seat, which makes
the monitoring of seat availability much more challenging.  

To make life easier for students, our goal is to design a system to monitor library seating. Our product
will be designed for and tested in the library at Zhejiang University International Campus. This system
will contain a physical sensing unit and a web interface application, which uses a cloud database to support
data communication between the two subsystems. There are three states for each seat: occupied by people,
occupied by items, and unoccupied. The sensing unit will combine different types of sensors, such as the
infrared sensor and the ultrasonic sensor, to determine the state of each seat. Then the occupancy data will
be sent to the cloud for the web interface application to visualize seat availability.

<img src ="https://github.com/LinHangzheng/SeatU/raw/master/image/visual_aid.jpg" width = "350" alt = "visaul_aid"/>

# Block Design
<img src ="https://github.com/LinHangzheng/SeatU/raw/master/image/block_diagram.jpg" width = "350" alt = "block_diagram"/>

# Browser UI Design
<img src ="https://github.com/LinHangzheng/SeatU/raw/master/image/browser_design.jpg" width = "350" alt = "browser_ui_design"/>
