/*
  WiFi Web Server

 A simple web server that shows the value of the analog input pins.
 using a WiFi shield.

 This example is written for a network using WPA encryption. For
 WEP or WPA, change the Wifi.begin() call accordingly.

 Circuit:
 * WiFi shield attached
 * Analog inputs attached to pins A0 through A5 (optional)

 created 13 July 2010
 by dlf (Metodo2 srl)
 modified 31 May 2012
 by Tom Igoe

 */

#include <SPI.h>
#include <WiFi101.h>


char ssid[] = "";      // your network SSID (name)
char pass[] = "";   // your network password
nt keyIndex = 0;                 // your network key Index number (needed only for WEP)

int status = WL_IDLE_STATUS;

WiFiServer server(80);

void setup() {
  //Initialize serial and wait for port to open:
  Serial.begin(9600);
  while (!Serial) {
    ; // wait for serial port to connect. Needed for native USB port only
  }

  // check for the presence of the shield:
  if (WiFi.status() == WL_NO_SHIELD) {
    Serial.println("WiFi shield not present");
    // don't continue:
    while (true);
  }

  // attempt to connect to Wifi network:
  while ( status != WL_CONNECTED) {
    Serial.print("Attempting to connect to SSID: ");
    Serial.println(ssid);
    // Connect to WPA/WPA2 network. Change this line if using open or WEP network:
    status = WiFi.begin(ssid, pass);

    // wait 10 seconds for connection:
    delay(10000);
  }
  server.begin();
  // you're connected now, so print out the status:
  printWifiStatus();
}


void loop() {
  // listen for incoming clients
  WiFiClient client = server.available();
  if (client) {
    Serial.println("new client");
    // an http request ends with a blank line
    String currentLine = ""; 
    bool vr = false;    
    while (client.connected()) {
      if (client.available()) {
        char c = client.read();             // read a byte, then
        Serial.write(c);                    // print it out the serial monitor
        if (c == '\n') {                    // if the byte is a newline character

          // if the current line is blank, you got two newline characters in a row.
          // that's the end of the client HTTP request, so send a response:
          if (currentLine.length() == 0) {
          // send a standard http response header
          client.println("HTTP/1.1 200 OK");

          
         Serial.println("hello");
         Serial.println(currentLine);
         
if (vr) {
  client.println("Content-Type: text/html");
  client.println("Connection: close");  // the connection will be closed after completion of the response
  //client.println("Refresh: 5");  // refresh the page automatically every 5 sec
  client.println();
  client.println("<!DOCTYPE HTML>");
  client.println("<html>");
  client.println("<head>");
  client.println("  <meta charset=\"utf-8\">");
  client.println("  <title>Snowman</title>");
  client.println("  <meta name=\"description\" content=\"Snowman\">");
  client.println("  <script src=\"https://aframe.io/releases/0.3.2/aframe.min.js\"></script>");
  client.println("  <script src=\"https://rondagdag.github.io/aframe-arduino-snowman/aframe-particle-system-component.min.js\"></script>");
  //client.println("  <script src=\"https://rondagdag.github.io/aframe-arduino-snowman/components/aabb-collider.js\"></script>");
  //client.println("  <script src=\"https://rondagdag.github.io/aframe-arduino-snowman/components/grab.js\"></script>");
  client.println("  <script src=\"https://rondagdag.github.io/aframe-arduino-snowman/components/aframe-extras.min.js\"></script>"); 
  client.println("</head>");
  client.println("<body>");
  client.println("  <a-scene>");
  client.println("  <a-assets>");
  client.println("      <img id=\"snowy\" crossorigin=\"anonymous\" src=\"https://rondagdag.github.io/a-frame-snowman/snowy.jpg\">");
  client.println("      <a-mixin id=\"snowTemplate\" position=\"0 2.25 -15\" particle-system=\"preset: snow; texture: https://rondagdag.github.io/a-frame-snowman/images/smokeparticle.png\"></a-mixin>");
  client.println("  </a-assets>");
  client.println("    <a-entity id=\"snowList\">");
  client.println("      <a-entity id='snow' mixin='snowTemplate'></a-entity>");
  client.println("    </a-entity>");
  //client.println("          <a-entity hand-controls='left' aabb-collider='objects: .sphere;' grab></a-entity>");
  //client.println("        <a-entity hand-controls='right' aabb-collider='objects: .sphere;' grab></a-entity>");
  client.println("      <a-entity id='leftController' static-body='shape: sphere; sphereRadius: 0.02;' vive-controls='hand: left' sphere-collider='objects: .throwable' grab></a-entity>");
  client.println("    <a-entity id='rightController' static-body='shape: sphere; sphereRadius: 0.02;' vive-controls='hand: right' sphere-collider='objects: .throwable' grab></a-entity>");

  client.println("    <a-sphere class='throwable' dynamic-body position='0 0.25 -0.5' radius='0.10' color='white'></a-sphere>");
  client.println("    <a-sphere class='throwable' dynamic-body position='0.20 0.25 -0.5' radius='0.10' color='white'></a-sphere>");
  client.println("    <a-sphere class='throwable' dynamic-body position='-0.20 0.25 -0.5' radius='0.10' color='white'></a-sphere>");
  client.println("    <a-sphere class='throwable' dynamic-body position='0 0.25 -0.15' radius='0.10' color='white'></a-sphere>");
  client.println("    <a-sphere class='throwable' dynamic-body position='0.20 0.25 -0.15' radius='0.10' color='white'></a-sphere>");
  client.println("    <a-sphere class='throwable' dynamic-body position='-0.20 0.25 -0.15' radius='0.10' color='white'></a-sphere>");
    
  client.println(" <a-entity static-body position='0 1 -5'>");
  client.println("    <a-sphere class='sphere' static-body position=\"0 0 -5\" radius=\"2\" material=\"shader: standard; color: #fff; metalness: 0; roughness: 1\"></a-sphere>");
  client.println("    <a-sphere class='sphere' static-body position=\"0 2 -5\" radius=\"1.7\" material=\"shader: standard; color: #fff; metalness: 0; roughness: 1\"></a-sphere>");
  client.println("    <a-sphere class='sphere' static-body position=\"0 4 -5\" radius=\"1.3\" material=\"shader: standard; color: #fff; metalness: 0; roughness: 1\"></a-sphere>");
  client.println("    <a-sphere class='sphere' static-body position=\"-0.4 4.3 -3.75\" radius=\"0.2\" material=\"shader: standard; color: #000; metalness: 0; roughness: 1\"></a-sphere>");
  client.println("    <a-sphere class='sphere' static-body position=\"0.4 4.3 -3.75\" radius=\"0.2\" material=\"shader: standard; color: #000; metalness: 0; roughness: 1\"></a-sphere>");
  client.println("    <a-cone static-body position=\"0 4 -3.38\" rotation=\"90 0 0\" radius-bottom=\"0.2\" radius-top=\"0\" material=\"shader: standard; color: #ce6548\"></a-cone>");
  client.println(" </a-entity>");
  client.println("    <a-plane static-body");
  client.println("      material=\"shader: flat; src: #snowy; repeat: 1 0.48\"");
  //client.println("      position=\"0 -1 0\"");
  client.println("      rotation=\"-90 0 0\"");
  client.println("      width=\"150\"");
  client.println("      height=\"50\"></a-plane>");
  client.println("    <a-entity geometry=\"primitive: sphere; radius: 50\"");
  client.println("        material=\"shader: flat; src: #snowy\"");
  client.println("        rotation=\"0 40 0\"");
  client.println("        position=\"0 0 0\"");
  client.println("        scale=\"1 1 -1\"></a-entity>");
  client.println("    <a-entity light=\"type: ambient; color: #405e94\"></a-entity>");
  client.println("    <a-entity light=\"type: directional; color: #FFF; intensity: 0.8\" position=\"5 5 10\"></a-entity>");
  client.println("  </a-scene>");
  client.println("<script>");
  
  client.println("var snowList = document.querySelector('#snowList');");
  client.println("var maxSnow = 50;");
  client.println("var indexSnow = snowList.childElementCount - 1;");
   
  client.println("function addSnow() {");
  client.println("  var newSnow = document.createElement('a-entity');");
  client.println("  newSnow.setAttribute('color', '#FF9500');");
  client.println("  newSnow.setAttribute('mixin', 'snowTemplate');");
  client.println("  return newSnow;");
  client.println("}");

  client.println("function disableSnow(snowElement) {");
  client.println("    var pg = snowElement.components['particle-system'].particleGroup;");
  client.println("    pg.emitters[0].disable();");
  client.println("}");

  client.println("function enableSnow(snowElement) {");
  client.println("    var pg = snowElement.components['particle-system'].particleGroup;");
  client.println("    pg.emitters[0].enable();");
  client.println("}");
  
  client.println("function removeSnow(snowList) {");
  client.println("  if (snowList.lastElementChild != null)");
  client.println("  { ");
  client.println("    var pg = snowList.lastElementChild.components['particle-system'].particleGroup;");
  client.println("    pg.emitters[0].disable();pg.emitters[0].remove();var emitter = snowList.lastElementChild;");
  client.println("    snowList.removeChild(snowList.lastElementChild);emitter = null");
  client.println("  }");
  client.println("}");

   client.println("function checkUpdates(url) {");
   client.println("var xhr = new XMLHttpRequest();");
   client.println("xhr.open('GET', url);");
   //client.println("xhr.onload = function(data) { console.log(data); }; ");
   client.println("    xhr.onreadystatechange = function() {");
   client.println("     if (xhr.readyState == 4 && xhr.status == 200) {  ");              
   //client.println("         document.getElementById(\"target\").innerHTML =    xmlHttpRequest.responseText;");
   client.println("           var result = JSON.parse(xhr.responseText); "); 
   
    client.println("var snowlist = document.querySelector('#snowList');");
   //client.println("removeSnow(snowList);");
   client.println("disableSnow(snowlist[indexSnow]);");
   client.println("indexSnow--;");
   client.println("if (result.channel0 > 470) {");
   client.println("       snowList.foreach(function(snow) { enableSnow(snow); });");
   //client.println("  var fragment = document.createDocumentFragment(); fragment.appendChild(addSnow(snowList));");
   //client.println("  fragment.appendChild(addSnow(snowList));");
   //client.println("  fragment.appendChild(addSnow(snowList));");
   //client.println("  snowList.appendChild(fragment); }");

   client.println("       console.log(result);");
   client.println("     }");
   client.println("   }");
   client.println(" }");
   client.println("xhr.send();");
   client.println("}");


  client.println("var docFrag = document.createDocumentFragment();");
  client.println("for(var i = 0; i < maxSnow; i++) {");
  client.println("  docFrag.appendChild(addSnow()); // Note that this does NOT go to the DOM");
  client.println("}");
  
  client.println("snowList.appendChild(docFrag);");
  client.println("snowList.foreach(function(snow) { disableSnow(snow); });");
  client.println("setInterval(function() { checkUpdates('/updates') }, 5000);");
  client.println("</script>");
          client.println("</body>");
          client.println("</html>");
} else {
    client.println("Content-Type: application/json");
  client.println("Connection: close");  // the connection will be closed after completion of the response
  client.println();
  int sensorReading = analogRead(0);
  client.print("{\"channel0\":");
  client.print(sensorReading);
  client.print("}");
          // output the value of each analog input pin
          //for (int analogChannel = 0; analogChannel < 6; analogChannel++) {
          //  int sensorReading = analogRead(analogChannel);
          //  client.print("analog input ");
          //  client.print(analogChannel);
          //  client.print(" is ");
          //  client.print(sensorReading);
          //  client.println("<br />");
          //}
}
          break;
          }
          else {      // if you got a newline, then clear currentLine:
            currentLine = "";
          }
        }
        else if (c != '\r') {    // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }

        // Check to see if the client request was "GET /H" or "GET /L":
        if (currentLine.endsWith("GET /vr")) {
          vr = true;
        }
      }
    }
    // give the web browser time to receive the data
    //delay(1);

    // close the connection:
    client.stop();
    Serial.println("client disonnected");
  }
}


void printWifiStatus() {
  // print the SSID of the network you're attached to:
  Serial.print("SSID: ");
  Serial.println(WiFi.SSID());

  // print your WiFi shield's IP address:
  IPAddress ip = WiFi.localIP();
  Serial.print("IP Address: ");
  Serial.println(ip);

  // print the received signal strength:
  long rssi = WiFi.RSSI();
  Serial.print("signal strength (RSSI):");
  Serial.print(rssi);
  Serial.println(" dBm");
}
}