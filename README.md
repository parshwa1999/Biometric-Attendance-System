# Biometric-Attendance-System

* ## Motivation
Few years back if you were to tell someone that the Geyser and bedroom lights in your home are connected to the internet, they would be baffled and might even criticize it as over-engineered products. But today with the advent of IoT, Smart cities etc the idea no longer sounds strange, we have devices around us that have become smarter by being able to communicate with the internet.

Attendance plays a major role in educational institutions. The most common means of taking attendance in the classroom is by calling out the roll numbers of students or asking the students to manually sign the attendance sheet, which is passed around during the lecture. The process of manually taking and maintaining the attendance records becomes highly cumbersome Biometric systems have reached a sufficiently advanced stage wherein they can now be deployed in systems without hampering portability. With the recent development of various cloud based computing and storage systems, data can be securely stored and retrieved whenever required. Primarily, fingerprints and iris images are considered to be the most reliable for use in biometric systems.

* ## Description And Final Outcome
In this project our aim is to leverage this IoT into the boring attendance system to make it smart and more effective. Most conventional attendance systems available today store the information over a micro SD card and have to be connected to software via a computer to access the information. Here, we will build a biometric attendance system using Arduino that scans for finger print and on successful identification of the person it will log the information to a cloud platform like ThingsBoard by using the ESP8266 Wi-Fi module. This information can then be displayed in the dashboard of ThingsBoard making it available for the required authorities to view and analysis information over the internet without having any direct physical access to the hardware. However the conventional Attendance system without involving IoT can also be built by following the link and Fingerprint sensor can be further used for many other biometric applications like Voting Machine, Security system etc.

* ## Block Diagram
![Block Diagram](.images/BlockDiagram.png)

* ## Circuit Diagram
![Block Diagram](.images/CircuitDiagram.png)

* ## Components Needed
  * Arduino UNO
  * 16x2 LCD Display
  * Ethernet Shield
  * R307 Fingerprint sensor (FPS)
  * Jumper wires
  * Push Buttons
  * Potentiometer
  * Resistors

* ## Operating Principle of Components
    * **R307 Fingerprint Sensor Module**
    The features of this sensor include the following.
      * It includes image collection as well as chip algorithm.
      * The fingerprint reader can perform lesser growth and can be fixed into a range of end products.
      * Power use is low, excellent performance, small in size, and less cost.
      * Optical technology which is used is professional, and exact module developed techniques.
      * The capabilities of image processing are good, and can effectively capture pictures up to 500 dpi resolution.
      
    **Working Principle:**
    The working principle of the fingerprint sensor mainly depends on the processing. The fingerprint processing mainly includes two elements namely enrollment and matching. In fingerprint enrolling, every user requires to place the finger twice. So that the system will check the finger images to process as well as to generate a pattern of the finger and it will be stored. When matching, a user places the finger using an optical sensor then the system will produce a pattern of the finger & compares it with the finger library templates. For 1:1 fingerprint matching, the system will evaluate the exits finger with a precise pattern which is selected within the module. Similarly, for 1: N matching, the scanning system will look for the complete finger records for the finger matching. In both situations, the scanning system will go back to the corresponding result, success otherwise crash.
    
    ![Block Diagram](.images/Fing.png)
    
    
    
    
