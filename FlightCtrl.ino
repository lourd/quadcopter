void FlightControl(){ //the motor speeds are calculated using the PID library and sent to the motors

  int PIDroll_val= (int)PIDroll.Compute((float)desRoll-actualRoll); //calculate roll value
  int PIDpitch_val= (int)PIDpitch.Compute((float)desPitch-actualPitch); //calculate pitch value
  int PIDyaw_val= (int)PIDyaw.Compute((float)desYaw-actualYaw); //calculate yaw value

  int m0_val=throttle+PIDroll_val+PIDpitch_val+PIDyaw_val; //value to send to motor 0
  int m1_val=throttle-PIDroll_val+PIDpitch_val-PIDyaw_val; //value to send to motor 1
  int m2_val=throttle+PIDroll_val-PIDpitch_val-PIDyaw_val; //value to send to motor 2
  int m3_val=throttle-PIDroll_val-PIDpitch_val+PIDyaw_val; //value to send to motor 3

//then send m0_val, m1_val, m2_val, m3_val to the 4 motors

//motor controllers http://hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=4312
//motors http://hobbyking.com/hobbyking/store/uh_viewItem.asp?idProduct=5354

}
