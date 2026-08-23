int cnt  = 0;   // this is gloabal varible;


    void taskA(){
    	 for( int i=0; i<10000 ;i++){
    	 	  cnt++;


    	 }
   }
   void taskB(){
    	 for( int i=0; i<10000 ;i++){
    	 	  cnt++;


    	 }
   }




int32_t main(){

 #ifndef ONLINE_JUDGE
     //for getting input from input.txt
     freopen("input1.txt","r",stdin);
     //for getting output to output.txt
     freopen("output1.txt","w",stdout);

 #endif
      thread t1(taskA);
      thread t2(taskB);
      t1.join();
      t2.join();
      cout<<cnt<<endl;
    
    

     

     
     return 0;
         
 }
