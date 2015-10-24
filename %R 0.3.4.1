//+------------------------------------------------------------------+
//|                                               My %R EA v 0.2.mq4 |
//|                                                             Theo |
//|                                      theonipponotaku@hotmail.com |
//+------------------------------------------------------------------+
#property copyright "TheoAdas"
#property link      "theonipponotaku@hotmail.com"
#property version   "1.00"
#property strict
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+


/*/--------------changes-------------------------//
//////////


 ////////////////
 3.Will add time control form 3:00 to 21:00----preparations copmlete need to embed from
  {experts98.mq4}---complete---alsoshows checks when trade is allowed!!!!---if trade allowed useless--abandoned
 ///////////////////
 4 Will add wait until market is open the check for time.---uselless it automatically 
 doesnt trade when market is closed.---abanddoned---
 /////////////
 5.Will close all orders on out of range time,and onlyonce=0;  ,,time and on de_init???????????
  out of range must try ??? also even better implement trailing stop.????
 ///////////////
 6.Take best values for inputss and run only them at a longer period 1 -3 months!!!!! 
 doing today -->(30 may-2015)
 
 7,Made the option to chose if the working  hours should be checked.
 
 8.Will have t otry optimization without hour constriction.---!!!----- done better results
 
 9.Made trailing stop +0.40 lepta lelelleel XDDDD---doen
 
 10.Making my second ea with the moving average.---done
 
 11.trailing stop makes it slower in optimization and generally
 
 12.redo the test without "accidentally " using tailstop-true  *facepalm---!!!!---done

 13.de init close all orders solved---done
 
 14.Did a mistake the EA must not have any shift only <=0 ,find all results with shift=0   ---???---
 
 15.Found a combination of lotsize(5euro) x22 in 3 months
 
 16.Added OrderLots to order close.
 
 17.Added AdjustLot() Function so lot size can increase exponentially based on free margin.
 
 18.Solved The AjustLot() round up problem add more to the second parameter (2-->3).
 
 19.Need to make the trailing stop to work and act as a correction manager---!!!
 done after 5 hours of work holy fuck---
 
 20.Will add the new trailing stop fucntion from experts98 works like a fuckn
  charm now only optimization with trailstop true and done madafaka!---???---
 
 21.Added the new trail stop also solved a problem wih minimum lotsize to be always 0.01 if if its less.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 22.THIS IS NOW A NEW EA BASED ON %R BUT WITH THE SAME STRUCTURE OF PSAR( failed ea but was a good lesson)
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*23.Made a include file withall the function to be called from main program.

 24.Have to make trade time schedule(mon-fri only).---!!!---done
 
 25.Replace all ordeselects with corsponding functions will have to make the 
 function return true if all is okay
   so that i can change the values of needed vars with control.----done!!!!---
 
 26.Have to understand why its not doinf anyting.Put print() everywhere.----!!!!----
 
 27.It works need to check if it works with weekends----????---- and with reenter.---????----
 
 28.Add Draw  on every indicator signal.---!!!!---
 
 29.There  wa a huge logical flaw with outer if blocking all inside code from 
 executing hink i have solved 
 it in v0.2.Made some bredy big changes.Does it work:---!!!---
 
 30.In CheckHours ,betweenlevelcheck didnt reset,ficed that.It was suppossed
  to be reset because otherwise it wouldnt check for level exiting and continue
   as if it had already been between levels.---!!!!---
 
 31.Still not working properly especially he signals from the indicator.
 Have to run without CheckHours.---!!!---
 
 32.Found that all positions close at the start of the weekend find how to
  battle that.
 But also it restores the jigsaw system wtf.----!!!---
 
 33.reenterswitch works properlymfounda syntax bug in orderswitch==2 the if was the same as 
 the orderswitch==1 making it imposible to change orders.
 
 24.Fixes a bug in olyonce==1 where orderswtich should be 1 for buy and 2 
 for sell but it was reversed.
 
 25.To make it check on closes i can use the Time[] array to comapre open 
 times if its a new open time it checks.---!!!!---
 
 26.Make the hour check as small as possible.---???---(add minutes)
 
 27.Solves a lot of bugs.Thingen of putting resume system for orderclosed 
 orders,have to check the last part of trading in the
  strat tester because it acts without %r hitting the levels---!!!---
 
 28. Found a hufe stupid mistake only one operation can be done in 
 one-lined-IFs(theo ones without brackets)---!!!---
 
 ----------0.3.3-------(all has on exit trade not on enter(overbought || oversold))
  
 29. First order must be the one that exits the levels(onlyonce)---!!!---
 
 40. Also the orderswitchers must be on exit too---!!!---
 
 41. Download MT5 for quicker optimization.---!!!---
 
 ----------0.3.4----------(4 levels)
 
 42. Since 0.3.4 I will another set of levels for a total of 4.This 
 theoretically increse even more my earnings---???---
 
 43. Removed useless btwlvlck after trdextck and everything works perfectly yay!
 ,even got rid of one useless drawtick---!!!---
 
 44.Added functios for lvl check,jigsaw system and trd on exit ,
 made global alt "pointers" for the passing and to the functions---!!!---
 
 45.Complete 2 set lvl ea---???---
 
 46.Test btwvlck---!!!---werks,test jigsaw()---!!!---,trdextck()---!!!---
 
 47.Ficed logical flaw in function brwlvck,jigsaw trdextck,now i can proceed.---!!!---
 
 48.Changed newbarck so that it has static variables




//-----------------changes end-----------*/

//+------------------------------------------------------------------+
//|  Functions   , Extern variables , inputs                         |
//+------------------------------------------------------------------+

#include <TheoLib.mqh>
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+

//+------------------------------------------------------------------+
//| Expert initialization function                                   |
//+------------------------------------------------------------------+
int OnInit()
  {
//---
   downlevel=-50-level;
   uplevel=-50+level;
//I 

//--shows vars for visual check in expert journal

//-is expert trade allowed in options
   if(IsTradeAllowed())Print("Expert Trade is allowed");
   else Print("Expert trade is not allowed");

//-is DLL import allowed   
   if(IsDllsAllowed()==true)Print("DLLs are allowed");
   else Print("DLLs are not allowed");
//-is there a server conncetion   
   if(IsConnected()==true)Print("Connection to Server Exists.Server ip :",ServerAddress());

   Print("Open orders and pending orders are:",OrdersTotal());

//---
   return(INIT_SUCCEEDED);
  }
//+------------------------------------------------------------------+
//| Expert deinitialization function                                 |
//+------------------------------------------------------------------+
void OnDeinit(const int reason)
  {
//---

  }
//+------------------------------------------------------------------+
//| Expert tick function                                             |
//+------------------------------------------------------------------+

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
void OnTick()
  {

/*
*/
//shows acoount leverage in chart windows on the left
   Comment("Account #",AccountNumber(),

           "\nlot 0.1 size is  ",MarketInfo(Symbol(),MODE_LOTSIZE)/1,
           "\nMagin required for 0.01 buy order  ",MarketInfo(Symbol(),MODE_MARGINREQUIRED)/100,
           "\nCheckHours=  ",CheckHours,
           "\nonlyonce=  ",onlyonce,
           "\nWPR",WPR(),
           "\nBetweenlevel: ",betweenlevelcheck,
           "\nreenterswitch: ",reenterswitch,
           "\norderswitch= ",orderswitch,
           "\nLast ORDER TYPE= ",trdrestype,
           "\nLast Error",ErrorDesc(GetLastError()),
           "\n_btwlvlck=",_btwlvlck,
           "\norderswitch1=",orderswitch1,
           "\nbetweenlevelcheck1=",betweenlevelcheck1,
           "\nreenterswitch1=",reenterswitch1,
           "\ntrdextck1=",trdextck1

           );

//Percent williams decision skeltal

//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
//Time Schedule

   if((DayOfWeek()==1 && Hour()>0) || (DayOfWeek()>1 && DayOfWeek()<5) || (DayOfWeek()==5 && Hour()<=23))
     {
      if(resumeorder==1)
        {
         ResumeLstOrder(); resumeorder=0;
        }
      CheckHours=true;

     }
   else
     {
      //Close all open orders and stop any activity CheckHours==false also reset ea with onlyonce=1 reenterswtich=1
      if(OrdersTotal()>0) //delete onlyonce,beetweenlevelck,reenterswitch to make it resetable.
        {
         //close Buy
         if(CheckOrderType()==OP_BUY)
           {
            OrderSelectCloseBuy(); DrawArrowUp("orderclose buy"); trdrestype=1;
           }
         //Close Sell
         if(CheckOrderType()==OP_SELL)
           {
            OrderSelectCloseSell(); DrawArrowUp("orderclose sell"); trdrestype=0;
           }
         resumeorder=1;
        }
      CheckHours=false; DrawThumb("end checkhours=false ");

     }

//End of time eschedule

//Draw a tick on chart
   if(DrawTickCheck)
     {
      DrawTick("draw tick check");
     }
//opnes the first order in the trading session
   if(onlyonce && CheckHours)
     {
      if(WPR()>uplevel && NewBarCk()) //open sell
        {
         orderswitch=2; _ordrswitch=orderswitch; onlyonce=0;onlyonce1=1; DrawTick("onlyonce sell");
        }
      else if(WPR()<downlevel && NewBarCk()) //open buy
        {
         orderswitch=1; _ordrswitch=orderswitch; onlyonce=0; onlyonce1=1; DrawTick("onlyonce buy");
        }
     }

//checks if beetween the two outer levels  for onlyonce--beetweenlvlck--.

   if(BtwLvlCk(level,orderswitch,betweenlevelcheck)==1)
     {
      betweenlevelcheck=_btwlvlck;
     }
//checks if next trades are ordered on exit.--trdectck--

   if(TrdExtCk(level,reenterswitch,orderswitch,betweenlevelcheck,trdextck)==1)
     {
      trdextck=_extck;
      reenterswitch=_rntrswitch;
      betweenlevelcheck=_btwlvlck;
     }

//----checks the position of %r in relation to levels until bwtweenlevels=true and it changed levels

   if(Jigsaw(level,reenterswitch,orderswitch,betweenlevelcheck,trdextck)==1)
     {
      trdextck=_extck;
      reenterswitch=_rntrswitch;
      orderswitch=_ordrswitch;
      betweenlevelcheck=_btwlvlck;
      onlyonce2=1;
     }
//second level set

   if(onlyonce2==1 && WPR()>(-50-level) && WPR()<(-50+level) && NewBarCk())
     {
      DrawArrowUp("2nd level set 2.1");
      trdextck1=1;
      orderswitch1=orderswitch;

      if(WPR()<(-50-level1) && WPR()>(-50+level1) && once==1) //was level instead of level1
        {
         reenterswitch1=2; betweenlevelcheck1=0; once=0; DrawArrowUp("2.2"); //del btwlvlck1=0; try setting is  
        }                                               //to 0 and setting to always 1 also must remove once since it will not know where its positioned for both lines
      else if(WPR()>(-50-level1) && WPR()<(-50+level1) && once==1)
        {
         reenterswitch1=1; betweenlevelcheck1=0; once=0; DrawArrowUp("2.3"); //del btwlvlck1=1;
        }
/*
      //checks if beetween the two outer levels  for onlyonce--beetweenlvlck--.

      if(BtwLvlCk(level1,orderswitch1,betweenlevelcheck1)==1)
        {
         betweenlevelcheck1=_btwlvlck; //DrawArrowUp("2.3");
        }
      //checks if next trades are ordered on exit.--trdectck--

      if(TrdExtCk(level1,reenterswitch1,orderswitch1,betweenlevelcheck1,trdextck1)==1)
        {
         trdextck1=_extck;
         reenterswitch1=_rntrswitch;
         betweenlevelcheck1=_btwlvlck;
         //DrawArrowUp("2.4");
        }

      //----checks the position of %r in relation to levels until bwtweenlevels=true and it changed levels

      if(Jigsaw(level1,reenterswitch1,orderswitch1,betweenlevelcheck1,trdextck1)==1)
        {
         trdextck1=_extck;
         reenterswitch1=_rntrswitch;
         orderswitch1=_ordrswitch;
         betweenlevelcheck1=_btwlvlck;
         //DrawArrowUp("2.5");
        }
*/
     }

//---
  }
//+------------------------------------------------------------------+
