bool flag[2] = {false, false};
int turn = 0;

int cnt = 0;


// Peterson's algorithm for Process 0
void process0()
{
    // I want to enter the critical section
    flag[0] = true;

    // Give Process 1 the chance
    turn = 1;

    // Wait if Process 1 also wants to enter
    // and it is Process 1's turn
    while (flag[1] && turn == 1)
    {
        // Busy waiting
    }

    // -------------------------
    // Critical Section
    // -------------------------
    for (int i = 0; i < 1000000; i++)
    {
        cnt++;
    }

    // I am leaving the critical section
    flag[0] = false;
}


// Peterson's algorithm for Process 1
void process1()
{
    // I want to enter the critical section
    flag[1] = true;

    // Give Process 0 the chance
    turn = 0;

    // Wait if Process 0 also wants to enter
    // and it is Process 0's turn
    while (flag[0] && turn == 0)
    {
        // Busy waiting
    }

    // -------------------------
    // Critical Section
    // -------------------------
    for (int i = 0; i < 1000000; i++)
    {
        cnt++;
    }

    // I am leaving the critical section
    flag[1] = false;
}




int32_t main(){

 #ifndef ONLINE_JUDGE
     //for getting input from input.txt
     freopen("input1.txt","r",stdin);
     //for getting output to output.txt
     freopen("output1.txt","w",stdout);

 #endif
  // Create two threads
    thread t1(process0);
    thread t2(process1);

    // Wait for both threads to finish
    t1.join();
    t2.join();

    // Print final value
    cout << "Final cnt = " << cnt << endl;
    
    

     

     
     return 0;
         
 }
