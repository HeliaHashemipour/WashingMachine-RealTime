#define S1 13
#define S2 12
#define S3 11
#define S4 10
#define S5 9

struct Job {
  int LED;
  int absoluteDeadline;
  int WCET;
  int semaphore;
};

struct Task {
  int relative_deadline;
  int WCET;
  int has_critical_section;
};

Task task1 = {50, 8, 0};
Task task2 = {40, 7, 1};
Task task3 = {30, 6, 1};
Task task4 = {20, 4, 0};
Task task5 = {10, 3, 1};

Job jobs[100];
int cur_taskID = -1;
int index = -1;
int current_semaphore = 0;
int current_time = 0;

void setup() {
  for (int i = 1; i <= 5; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, LOW);
  }

  for (int i = S1; i <= S5; i++) {
    pinMode(i, INPUT);
  }

  Serial2.begin(9600);
}

void loop() {
  if (digitalRead(S1) == 0) {  // Turning on the light
    index++;
    jobs[index] = {1, task1.relative_deadline + current_time, task1.WCET, task1.has_critical_section};
    Serial2.println();
    Serial2.print("Task 1 arrive at ");
    Serial2.println(current_time);
  }

  if (digitalRead(S2) == 0) {  // kids lock
    index++;
    jobs[index] = {2, task2.relative_deadline + current_time, task2.WCET, task2.has_critical_section};

    Serial2.println();
    Serial2.print("Task 2 arrive at ");
    Serial2.println(current_time);
  }

  if (digitalRead(S3) == 0) {  // wash
    index++;
    jobs[index] = {3, task3.relative_deadline + current_time, task3.WCET, task3.has_critical_section};
    Serial2.println();
    Serial2.print("Task 3 arrive at ");
    Serial2.println(current_time);
  }

  if (digitalRead(S4) == 0) {  // spin
    index++;
    jobs[index] = {4, task4.relative_deadline + current_time, task4.WCET, task4.has_critical_section};
    Serial2.println();
    Serial2.print("Task 4 arrive at ");
    Serial2.println(current_time);
  }

  if (digitalRead(S5) == 0) {  // rinse
    index++;
    jobs[index] = {5, task5.relative_deadline + current_time, task5.WCET, task5.has_critical_section};
    Serial2.println();
    Serial2.print("Task 5 arrive at ");
    Serial2.println(current_time);
  }

  if (current_semaphore == 1) {
    if (current_time > jobs[cur_taskID].absoluteDeadline) {//miss
      jobs[cur_taskID].LED = 0;
      Serial2.println("deadline");
      current_semaphore = 0;
    } else {
      jobs[cur_taskID].WCET--;

      for (int i = 1; i <= 5; i++) {
        digitalWrite(i, LOW);
      }

      int LED = jobs[cur_taskID].LED;
      digitalWrite(LED, HIGH);
      delay(100);
    }

    if (jobs[cur_taskID].WCET == 0) {
      digitalWrite(jobs[cur_taskID].LED, LOW);
      jobs[cur_taskID].LED = 0;
      Serial2.print("finished ");
      Serial2.println(cur_taskID);
      current_semaphore = 0;
    }
  }
  
  if (current_semaphore == 0) {
    int min_taskID = -1;
    int min_deadline = 10000;

    for (int i = 0; i <= index; i++) { //edf
      if (current_time > jobs[i].absoluteDeadline) {//miss
        if (jobs[i].LED != 0) {
          Serial2.print("task");
          Serial2.print(i);
          Serial2.println(" missed.");
        }
        digitalWrite(jobs[i].LED, LOW);
        jobs[i].LED = 0;
      }

      if (jobs[i].LED != 0) {
        if (jobs[i].absoluteDeadline <= min_deadline) {
          min_taskID = i;
          min_deadline = jobs[i].absoluteDeadline;
        }
      }
    }

    if (min_taskID != -1) {
      cur_taskID = min_taskID;
      current_semaphore = jobs[min_taskID].semaphore;
      jobs[min_taskID].WCET--;

      for (int i = 1; i <= 5; i++) {
        digitalWrite(i, LOW);
      }

      int LED = jobs[min_taskID].LED;
      Serial2.print("LED: ");
      Serial2.println(LED);

      digitalWrite(LED, HIGH);
      delay(100);

      if (jobs[cur_taskID].WCET == 0) {
        digitalWrite(jobs[cur_taskID].LED, LOW);
        jobs[cur_taskID].LED = 0;
        current_semaphore = 0;
      }
    }
  }

  current_time++;
  delay(100);
  Serial2.print("taskID: ");
  Serial2.println(cur_taskID);
}