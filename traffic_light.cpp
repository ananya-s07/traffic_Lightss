#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>
#include <ctime>
using namespace std;
atomic<bool> stop(false);
enum TrafficLight {
    RED,
    GREEN,
    YELLOW};
void logMessage(const std::string& message) {
    std::time_t now = std::time(nullptr);
    std::tm* localTime = std::localtime(&now);

    cout << "["
         << localTime->tm_hour << ":"
         << localTime->tm_min << ":"
         << localTime->tm_sec << "] "
         << message << endl;
}
void Traffic_light(TrafficLight &Currlight){
    while (!stop){
    switch (Currlight){
    case RED:
    logMessage("TRAFFIC LIGHT : RED (STOP)");
 std::this_thread::sleep_for(chrono::seconds(5));
Currlight= YELLOW;
break;
 case YELLOW:
  logMessage("TRAFFIC LIGHT : YELLOW (WAIT!)");
std :: this_thread::sleep_for(chrono::seconds(5));
Currlight=GREEN;
break;
 case GREEN:
  logMessage("TRAFFIC LIGHT : GREEN (GO:))");
std:: this_thread::sleep_for(chrono::seconds(2));
Currlight=RED;
break;}}}
int main(){
    TrafficLight Currlight =RED;
thread colour(Traffic_light, std::ref(Currlight));
cout << "Press ENTER to stop\n";
    cin.get();

    
    stop = true;
    colour.join();

    cout << "Program exited safely hehe :)\n";
return 0;
}