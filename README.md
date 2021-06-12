# Rainfall-and-Soil-Shift-Monitoring-System-through-Transmission-Radio-and-GPRS

<h1> Introduction </h1>
Landslides or ground surface movements can be caused by high rainfall intensity. The negative impact of landslides can be minimized by continuous monitoring, on lands that are expected to be a landslide. Technology can help in this supervision, technological solutions that have been carried out include systems that are able to utilize water content in the soil and soil grinding as an indicator of landslides, but this system cannot be monitored remotely. 

In this Final Project, a tool is made to monitor rainfall and land shifts. The advantages of this monitoring tool can be used in areas that are not covered by telecommunications networks. This monitoring tool is divided into 3 modules: Client, Master, and Server. The client receives a response from the environment which is observed in the form of rainwater data collected in a place and ground movement. The data is transmitted through 433MHz RF media and the data is received by the Master. Data received by the Master is stored in the data logger and sent to the Server via the internet network. Data received by the server in accordance with the data sent by the client is displayed in the form of information tables on a web page. The server also sends notification messages via E-mail and SMS when a hazard occurs. 

Based on measurements and simulations, sending data from the Client to the Master functions with a maximum distance of 200m. Every 1 minute the data received from Client 2 is 108 data, while Client 1 is 33 data. The time interval from Master to Server for Client 1 is 1-30 seconds, while for Client 2 is 2-4 seconds. The delivery time difference is due to the different delay in each client and the unstable provider network conditions. 
