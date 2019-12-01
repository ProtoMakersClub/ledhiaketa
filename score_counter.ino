
#define CLICKS_PER_POINT 1

bool a_btn_prev_status = LOW;
bool b_btn_prev_status = LOW;

void countScore() {
  bool a_btn_status = digitalRead(a_btn);
  bool b_btn_status = digitalRead(b_btn);

  if (a_btn_status != a_btn_prev_status && a_btn_status == LOW) {
    a_clicks++;
  }


  if (b_btn_status != b_btn_prev_status && b_btn_status == LOW) {
    b_clicks++;
  }
  a_score = (a_clicks - (a_clicks % CLICKS_PER_POINT) ) / CLICKS_PER_POINT;
  b_score = (b_clicks - (b_clicks % CLICKS_PER_POINT) ) / CLICKS_PER_POINT;

  a_btn_prev_status = a_btn_status;
  b_btn_prev_status = b_btn_status;

  delay(5);
}

void countSetup() {
  pinMode(a_btn, INPUT_PULLUP);
  pinMode(b_btn, INPUT_PULLUP);


}
