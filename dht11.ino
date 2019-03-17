// copyright thecustomizewindows.com ; abhishek ghosh
// add <Adafruit_Sensor.h>, <DHT.h> and <DHT_U.h>

#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>
#define DHTPIN            15         // Pin which is connected to the DHT sensor.
// type the model of sensor in use, we are using DHT 11, if you are using DHT 21 or DHT 22 change it
#define DHTTYPE           DHT11     
DHT_Unified dht(DHTPIN, DHTTYPE);
uint32_t delayMS;
void setup() {
  Serial.begin(9600); 
  dht.begin();
  Serial.println("Modified Temperature, Humidity Serial Monitor Example");
  sensor_t sensor;
  dht.temperature().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Temperature");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println(" *C");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println(" *C");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println(" *C");  
  Serial.println("------------------------------------");
  dht.humidity().getSensor(&sensor);
  Serial.println("------------------------------------");
  Serial.println("Humidity");
  Serial.print  ("Sensor:       "); Serial.println(sensor.name);
  Serial.print  ("Driver Ver:   "); Serial.println(sensor.version);
  Serial.print  ("Unique ID:    "); Serial.println(sensor.sensor_id);
  Serial.print  ("Max Value:    "); Serial.print(sensor.max_value); Serial.println("%");
  Serial.print  ("Min Value:    "); Serial.print(sensor.min_value); Serial.println("%");
  Serial.print  ("Resolution:   "); Serial.print(sensor.resolution); Serial.println("%");  
  Serial.println("------------------------------------");
  delayMS = sensor.min_delay / 1000;
}
void loop() {
  delay(delayMS);
  sensors_event_t event;  
  dht.temperature().getEvent(&event);
  if (isnan(event.temperature)) {
    Serial.println("Error reading temperature!");
  }
  else {
    Serial.print("Temperature: ");
    Serial.print(event.temperature);
    Serial.println(" *C");
  }
  dht.humidity().getEvent(&event);
  if (isnan(event.relative_humidity)) {
    Serial.println("Error reading humidity!");
  }
  else {
    Serial.print("Humidity: ");
    Serial.print(event.relative_humidity);
    Serial.println("%");
  }
}
