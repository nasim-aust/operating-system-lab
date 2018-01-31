import java.util.Scanner;
import java.util.concurrent.Semaphore;
import java.util.logging.Level;
import java.util.logging.Logger;
 
class Cp
{
    // an item
    static int readCount=0;
    static Semaphore mutex = new Semaphore(1);
    static Semaphore db = new Semaphore(1);
    
    

 
// Producer class
static class Reader implements Runnable
{
    
    public void run() {
          Thread t;
          
         try {
            
            mutex.acquire();
            readCount++;
            if(readCount==1){
                db.acquire();
            
            
            t = Thread.currentThread();
               
            System.out.println("Thread " + t.getName() + " is reading");
            }
               mutex.release();
               t = Thread.currentThread();
               System.out.println("Thread " + t.getName() + " has finished reading");
               
            mutex.acquire();
            readCount--;
            if(readCount==0){
                db.release();
            }
            mutex.release();
       
        } catch (InterruptedException ex) {
            Logger.getLogger(Reader.class.getName()).log(Level.SEVERE, null, ex);
        }
           
    }
}

static class Writer implements Runnable
{
    
    public void run() {
           Thread t1;
           Scanner writing = new Scanner(System.in);
          
         try {
            t1 = Thread.currentThread();
            
            System.out.println("Thread " + t1.getName() + " is preparing data");
            db.acquire();
            System.out.println("Thread " + t1.getName() + " is writing");
            
            String w = writing.next();
            System.out.println(w);
            db.release();
            System.out.println("Thread " + t1.getName() + " has finished writing");
            
       
        } catch (InterruptedException ex) {
            Logger.getLogger(Writer.class.getName()).log(Level.SEVERE, null, ex);
        }
         //writing.close();
           
    }
}

 


    public static void main(String args[]) 
    {
        // creating buffer queue
        
        Reader read = new Reader();
        Writer write = new Writer();
        Thread person1 = new Thread(read);
        person1.setName("Reader 1");
        Thread person2 = new Thread(read);
        person2.setName("Reader 2");
        Thread person3 = new Thread(write);
        person3.setName("Writer 1");
        
        person1.start();
        person2.start();
        person3.start();
        
    }
}
