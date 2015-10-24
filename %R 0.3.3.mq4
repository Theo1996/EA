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
1.Ordeclose now works properly.
///////////////////
2.need to optimize Parabolic sar create a sheet with the results on different step maximum and shift.?--not done yet---!!!! 
      creeated automatically by optimization in the tester made X6 times the lot size in one week.
      i have sheet with all the results and the inputs used also want to print or write as much as possible them.
      ,i think shift is the most appropriate ooption t ochange all the other dont do shit.
   //--------tester-------Step 0.2 ,max 0.2 ,H30 ,5 days,
      shift=
      0---  -6.04
      1---- 5.31
      2---- 5.92
      3---  -6.40          //shift only takes positive numbers(at least they are the ones that give me the best profit),meaning 1 shift 1 bar back,2 shift two bars etc...
      4--- 3.55
      -1---
       -2---
      -3---
      -4---
      negative shift not working for some reason,but i found that an isar with step 0.2 and max 0.62-0.32 works better
      a sensitive sar doesnt work properly without corection base on nuy or sell,if sell isar()+0.0050  if buy isar()-0.0050???????--base correction not working well with super sensitive sar--abandoned--
        But not sensitive one works fine even without corrections?????--not implemented yet OR TRY To implement negative shift since it wasnt working , in expert98 create objectreate at value of idar shift -10 ,so the rusults will be visible

 ////////////////
 3.Will add time control form 3:00 to 21:00----preparations copmlete need to embed from {experts98.mq4}---complete---alsoshows checks when trade is allowed!!!!---if trade allowed useless--abandoned
 ///////////////////
 4 Will add wait until market is open the check for time.---uselless it automatically doesnt trade when market is closed.---abanddoned---
 /////////////
 5.Will close all orders on out of range time,and onlyonce=0;  ,,time and on de_init??????????? out of range must try ??? also even better implement trailing stop.????
 ///////////////
 6.Take best values for inputss and run only them at a longer period 1 -3 months!!!!! doing today -->(30 may-2015)
 
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
 
 19.Need to make the trailing stop to work and act as a correction manager---!!!done after 5 hours of work holy fuck---
 
 20.Will add the new trailing stop fucntion from experts98 works like a fuckn charm now only optimization with trailstop true and done madafaka!---???---
 
 21.Added the new trail stop also solved a problem wih minimum lotsize to be always 0.01 if if its less.
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
 22.THIS IS NOW A NEW EA BASED ON %R BUT WITH THE SAME STRUCTURE OF PSAR( failed ea but was a good lesson)
++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++

*23.Made a include file withall the function to be called from main program.

 24.Have to make trade time schedule(mon-fri only).---!!!---done
 
 25.Replace all ordeselects with corsponding functions will have to make the function return true if all is okay
   so that i can change the values of needed vars with control.----done!!!!---
 
 26.Have to understand why its not doinf anyting.Put print() everywhere.----!!!!----
 
 27.It works need to check if it works with weekends----????---- and with reenter.---????----
 
 28.Add Draw  on every indicator signal.---!!!!---
 
 29.There  wa a huge logical flaw with outer if blocking all inside code from executing hink i have solved 
 it in v0.2.Made some bredy big changes.Does it work:---!!!---
 
 30.In CheckHours ,betweenlevelcheck didnt reset,ficed that.It was suppossed to be reset because otherwise it 
 wouldnt check for level exiting and continue as if it had already been between levels.---!!!!---
 
 31.Still not working properly especially he signals from the indicator.Have to run without CheckHours.---!!!---
 
 32.Found that all positions close at the start of the weekend find how to battle that.But also it restores the jigsaw system wtf.----!!!---
 
 33.reenterswitch works properlymfounda syntax bug in orderswitch==2 the if was the same as the orderswitch==1 making it imposible to change orders.
 
 24.Fixes a bug in olyonce==1 where orderswtich should be 1 for buy and 2 for sell but it was reversed.
 
 25.To make it check on closes i can use the Time[] array to comapre open times if its a new open time it checks.---!!!!---
 
 26.Make the hour check as small as possible.---???---(add minutes)
 
 27.Solves a lot of bugs.Thingen of putting resume system for orderclosed orders,have to check the last part of trading in the
  strat tester because it acts without %r hitting the levels---!!!---
 
 28. Found a hufe stupid mistake only one operation can be done in one-lined-IFs(theo ones without brackets)---!!!---
 ---------0.3.3-------(all has on exit trade not on enter(overbought || oversold))
 29. First order must be the one that exits the levels(onlyonce)---!!!---
 
 40. Also the orderswitchers must be on exit too---!!!---
 
 41 Download MT5 for quicker optimization.---???---
 ----------0.3.4------(4 levels)----
 
 42. Since 0.3.4 I will another set of levels for a total of 4.This theoretically increse even more my earnings---???---




//-----------------changes end-----------*/
/*if you want to include files write #include <filename.h>,
  angel brackets mean default directory of inlcude files 
  if "filename.h" the file is taken from the directory of the source program,
  The#inlcude line will be replaced with the contents of the file.
  #include <My ISAR v0.1.>*/

/* to add market info()   ,spread lot size tick value trade allowed
  double MarketInfo(string symbol, int type) 
  Returns value from Market watch window.
   Parameters
   symbol  -   Instrumentsymbol.
   type  -   Returningdata typeindex.Itcanbeanyof Marketinformationidentifiersvalue.
   Sample
   double var;
   var=MarketInfo("EURUSD",MODE_BID);
*/

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
           "\nLast Error",ErrorDesc(GetLastError())
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
         orderswitch=2; onlyonce=0;onlyonce1=1; DrawTick("onlyonce sell");
        }
      else if(WPR()<downlevel && NewBarCk()) //open buy
        {
         orderswitch=1;onlyonce=0; onlyonce1=1; DrawTick("onlyonce buy");
        }
     }

//checks if beetween the two outer levels for onlyonce
   if(WPR()<uplevel && WPR()>downlevel && CheckHours && onlyonce==0 && betweenlevelcheck && NewBarCk())
     {
      if(onlyonce1==1 && orderswitch==2)
        {
         OpenSell(); onlyonce1=0;
        }
      else if(onlyonce1==1 && orderswitch==1)
        {
         OpenBuy(); onlyonce1=0;
        }

      betweenlevelcheck=false; DrawTick("beetweencheck=false");
     }
//checks if next trades are ordered on exit
   if(WPR()<uplevel && WPR()>downlevel && trdextck==0 && CheckHours && NewBarCk() )
     {
      if(orderswitch==1)
        {
         if(OrderSelectCloseOpenBuy()==1) //close,buy,orderswitch=1,betweenlevelcheck=1,reenterswitch=1
           {
            betweenlevelcheck=true; reenterswitch=1; DrawTick("trdextck buy"); trdextck=1;
           }
        }
      else if(orderswitch==2)
        {
         if(OrderSelectCloseOpenSell()==1) //close sell,buy,reenterswitch=1,betweenlevelcheck=1
           {
             betweenlevelcheck=true; reenterswitch=1; DrawTick("trdextck sell"); trdextck=1;
           }
        }
     }
//----checks the position of %r in relation to levels until bwtweenlevels=true and it changed levels
   if(orderswitch==1 && betweenlevelcheck==false && NewBarCk() && CheckHours && trdextck)
     { //while it reenters and is started by a buy if it goes above uplevel it changes to 2 1=buy 2=sell------------------------

      if(WPR()<downlevel && reenterswitch==1)
        {                                                                           //first checks if it goes below downlevel
         if(OrderSelectCloseOpenSell()==1)                                          //close previous open sell,reenterswitch=2
           {
            reenterswitch=2; DrawTick("1.1");
           }
        }
      else if(WPR()<uplevel && WPR()>downlevel && reenterswitch==2)
        {                                                                           //then it checks if it went betweeen the two levels again
         if(OrderSelectCloseOpenBuy()==1)                                           //close previous ,open buy, 
           {
            reenterswitch=1;   DrawTick("1.2");
           }
        }
      else if(WPR()>uplevel)
        {
         trdextck=0;orderswitch=2; DrawTick("1.3");
         //or if it immediately went above uplevel

        }
     }
   else if(orderswitch==2 && betweenlevelcheck==false && NewBarCk() && CheckHours)
     {//-----------------------------------------------------------------------------------------------------------------
      if(WPR()>uplevel && reenterswitch==1)
        {                                                         //checks
         if(OrderSelectCloseOpenBuy()==1)                         //close previous open buy,reenterswitch=2
           {
            reenterswitch=2; DrawTick("2.1");
           }
        }
      else if(WPR()<uplevel && WPR()>downlevel && reenterswitch==2)
        {
         if(OrderSelectCloseOpenSell()==1) //close previous open sell 
           {
            reenterswitch=1; DrawTick("2.2");
           }
        }
      else if(WPR()<downlevel)
        {
         trdextck=0; orderswitch=1; DrawTick("2.3");

        }
     }

//---
  }
//+------------------------------------------------------------------+
