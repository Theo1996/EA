//+------------------------------------------------------------------+
//|                                                    Libraries.mq4 |
//|                                                             Theo |
//|                                                                h |
//+------------------------------------------------------------------+
#property library
#property copyright "Theo"
#property link      "h"
#property version   "1.00"
#property strict
//+------------------------------------------------------------------+
//| My function                                                      |
//+------------------------------------------------------------------+
// int MyCalculator(int value,int value2) export
//   {
//    return(value+value2);
//   }
//+------------------------------------------------------------------+
int ErrorDesc(int a)
  {
//Trade Server Errors
   if(a==   0   ) Print("	ERR_NO_ERROR	No error returned.	");
   if(a==   1   ) Print("	ERR_NO_RESULT	No error returned, but the result is unknown.	");
   if(a==   2   ) Print("	ERR_COMMON_ERROR	Common error.	");
   if(a==   3   ) Print("	ERR_INVALID_TRADE_PARAMETERS	Invalid trade parameters.	");
   if(a==   4   ) Print("	ERR_SERVER_BUSY	Trade server is busy.	");
   if(a==   5   ) Print("	ERR_OLD_VERSION	Old version of the client terminal.	");
   if(a==   6   ) Print("	ERR_NO_CONNECTION	No connection with trade server.	");
   if(a==   7   ) Print("	ERR_NOT_ENOUGH_RIGHTS	Not enough rights.	");
   if(a==   8   ) Print("	ERR_TOO_FREQUENT_REQUESTS	Too frequent requests.	");
   if(a==   9   ) Print("	ERR_MALFUNCTIONAL_TRADE	Malfunctional trade operation.	");
   if(a==   64   ) Print("	ERR_ACCOUNT_DISABLED	Account disabled.	");
   if(a==   65   ) Print("	ERR_INVALID_ACCOUNT	Invalid account.	");
   if(a==   128   ) Print("	ERR_TRADE_TIMEOUT	Trade timeout.	");
   if(a==   129   ) Print("	ERR_INVALID_PRICE	Invalid price.	");
   if(a==   130   ) Print("	ERR_INVALID_STOPS	Invalid stops.	");
   if(a==   131   ) Print("	ERR_INVALID_TRADE_VOLUME	Invalid trade volume.	");
   if(a==   132   ) Print("	ERR_MARKET_CLOSED	Market is closed.	");
   if(a==   133   ) Print("	ERR_TRADE_DISABLED	Trade is disabled.	");
   if(a==   134   ) Print("	ERR_NOT_ENOUGH_MONEY	Not enough money.	");
   if(a==   135   ) Print("	ERR_PRICE_CHANGED	Price changed.	");
   if(a==   136   ) Print("	ERR_OFF_QUOTES	Off quotes.	");
   if(a==   137   ) Print("	ERR_BROKER_BUSY	Broker is busy.	");
   if(a==   138   ) Print("	ERR_REQUOTE	Requote.	");
   if(a==   139   ) Print("	ERR_ORDER_LOCKED	Order is locked.	");
   if(a==   140   ) Print("	ERR_LONG_POSITIONS_ONLY_ALLOWED	Long positions only allowed.	");
   if(a==   141   ) Print("	ERR_TOO_MANY_REQUESTS	Too many requests.	");
   if(a==   145   ) Print("	ERR_TRADE_MODIFY_DENIED	Modification denied because an order is too close to market.	");
   if(a==   146   ) Print("	ERR_TRADE_CONTEXT_BUSY	Trade context is busy.	");
   if(a==   147   ) Print("	ERR_TRADE_EXPIRATION_DENIED	Expirations are denied by broker.	");
   if(a==   148   ) Print("	ERR_TRADE_TOO_MANY_ORDERS	The amount of opened and pending orders has reached the limit set by a broker. 	");
//--runtime errors
   if(a==   4000   ) Print("	ERR_NO_MQLERROR	No error.	");
   if(a==   4001   ) Print("	ERR_WRONG_FUNCTION_POINTER	Wrong function pointer.	");
   if(a==   4002   ) Print("	ERR_ARRAY_INDEX_OUT_OF_RANGE	Array index is out of range.	");
   if(a==   4003   ) Print("	ERR_NO_MEMORY_FOR_FUNCTION_CALL_STACK	No memory for function call stack.	");
   if(a==   4004   ) Print("	ERR_RECURSIVE_STACK_OVERFLOW	Recursive stack overflow.	");
   if(a==   4005   ) Print("	ERR_NOT_ENOUGH_STACK_FOR_PARAMETER	Not enough stack for parameter.	");
   if(a==   4006   ) Print("	ERR_NO_MEMORY_FOR_PARAMETER_STRING	No memory for parameter string.	");
   if(a==   4007   ) Print("	ERR_NO_MEMORY_FOR_TEMP_STRING	No memory for temp string.	");
   if(a==   4008   ) Print("	ERR_NOT_INITIALIZED_STRING	Not initialized string.	");
   if(a==   4009   ) Print("	ERR_NOT_INITIALIZED_ARRAYSTRING	Not initialized string in an array.	");
   if(a==   4010   ) Print("	ERR_NO_MEMORY_FOR_ARRAYSTRING	No memory for an array string.	");
   if(a==   4011   ) Print("	ERR_TOO_LONG_STRING	Too long string.	");
   if(a==   4012   ) Print("	ERR_REMAINDER_FROM_ZERO_DIVIDE	Remainder from zero divide.	");
   if(a==   4013   ) Print("	ERR_ZERO_DIVIDE	Zero divide.	");
   if(a==   4014   ) Print("	ERR_UNKNOWN_COMMAND	Unknown command.	");
   if(a==   4015   ) Print("	ERR_WRONG_JUMP	Wrong jump.	");
   if(a==   4016   ) Print("	ERR_NOT_INITIALIZED_ARRAY	Not initialized array.	");
   if(a==   4017   ) Print("	ERR_DLL_CALLS_NOT_ALLOWED	DLL calls are not allowed.	");
   if(a==   4018   ) Print("	ERR_CANNOT_LOAD_LIBRARY	Cannot load library.	");
   if(a==   4019   ) Print("	ERR_CANNOT_CALL_FUNCTION	Cannot call function.	");
   if(a==   4020   ) Print("	ERR_EXTERNAL_EXPERT_CALLS_NOT_ALLOWED	EA function calls are not allowed.	");
   if(a==   4021   ) Print("	ERR_NOT_ENOUGH_MEMORY_FOR_RETURNED_STRING	Not enough memory for a string returned from a function.	");
   if(a==   4022   ) Print("	ERR_SYSTEM_BUSY	System is busy.	");
   if(a==   4050   ) Print("	ERR_INVALID_FUNCTION_PARAMETERS_COUNT	Invalid function parameters count.	");
   if(a==   4051   ) Print("	ERR_INVALID_FUNCTION_PARAMETER_VALUE	Invalid function parameter value.	");
   if(a==   4052   ) Print("	ERR_STRING_FUNCTION_INTERNAL_ERROR	String function internal error.	");
   if(a==   4053   ) Print("	ERR_SOME_ARRAY_ERROR	Some array error.	");
   if(a==   4054   ) Print("	ERR_INCORRECT_SERIES_ARRAY_USING	Incorrect series array using.	");
   if(a==   4055   ) Print("	ERR_CUSTOM_INDICATOR_ERROR	Custom indicator error.	");
   if(a==   4056   ) Print("	ERR_INCOMPATIBLE_ARRAYS	Arrays are incompatible.	");
   if(a==   4057   ) Print("	ERR_GLOBAL_VARIABLES_PROCESSING_ERROR	Global variables processing error.	");
   if(a==   4058   ) Print("	ERR_GLOBAL_VARIABLE_NOT_FOUND	Global variable not found.	");
   if(a==   4059   ) Print("	ERR_FUNCTION_NOT_ALLOWED_IN_TESTING_MODE	Function is not allowed in testing mode.	");
   if(a==   4060   ) Print("	ERR_FUNCTION_NOT_CONFIRMED	Function is not confirmed.	");
   if(a==   4061   ) Print("	ERR_SEND_MAIL_ERROR	Mail sending error.	");
   if(a==   4062   ) Print("	ERR_STRING_PARAMETER_EXPECTED	String parameter expected.	");
   if(a==   4063   ) Print("	ERR_INTEGER_PARAMETER_EXPECTED	Integer parameter expected.	");
   if(a==   4064   ) Print("	ERR_DOUBLE_PARAMETER_EXPECTED	Double parameter expected.	");
   if(a==   4065   ) Print("	ERR_ARRAY_AS_PARAMETER_EXPECTED	Array as parameter expected.	");
   if(a==   4066   ) Print("	ERR_HISTORY_WILL_UPDATED	Requested history data in updating state.	");
   if(a==   4067   ) Print("	ERR_TRADE_ERROR	Some error in trade operation execution.	");
   if(a==   4099   ) Print("	ERR_END_OF_FILE	End of a file.	");
   if(a==   4100   ) Print("	ERR_SOME_FILE_ERROR	Some file error.	");
   if(a==   4101   ) Print("	ERR_WRONG_FILE_NAME	Wrong file name.	");
   if(a==   4102   ) Print("	ERR_TOO_MANY_OPENED_FILES	Too many opened files.	");
   if(a==   4103   ) Print("	ERR_CANNOT_OPEN_FILE	Cannot open file.	");
   if(a==   4104   ) Print("	ERR_INCOMPATIBLE_ACCESS_TO_FILE	Incompatible access to a file.	");
   if(a==   4105   ) Print("	ERR_NO_ORDER_SELECTED	No order selected.	");
   if(a==   4106   ) Print("	ERR_UNKNOWN_SYMBOL	Unknown symbol.	");
   if(a==   4107   ) Print("	ERR_INVALID_PRICE_PARAM	Invalid price.	");
   if(a==   4108   ) Print("	ERR_INVALID_TICKET	Invalid ticket.	");
   if(a==   4109   ) Print("	ERR_TRADE_NOT_ALLOWED	Trade is not allowed.	");
   if(a==   4110   ) Print("	ERR_LONGS_NOT_ALLOWED	Longs are not allowed.	");
   if(a==   4111   ) Print("	ERR_SHORTS_NOT_ALLOWED	Shorts are not allowed.	");
   if(a==   4200   ) Print("	ERR_OBJECT_ALREADY_EXISTS	Object already exists.	");
   if(a==   4201   ) Print("	ERR_UNKNOWN_OBJECT_PROPERTY	Unknown object property.	");
   if(a==   4202   ) Print("	ERR_OBJECT_DOES_NOT_EXIST	Object does not exist.	");
   if(a==   4203   ) Print("	ERR_UNKNOWN_OBJECT_TYPE	Unknown object type.	");
   if(a==   4204   ) Print("	ERR_NO_OBJECT_NAME	No object name.	");
   if(a==   4205   ) Print("	ERR_OBJECT_COORDINATES_ERROR	Object coordinates error.	");
   if(a==   4206   ) Print("	ERR_NO_SPECIFIED_SUBWINDOW	No specified subwindow.	");
   if(a==   4207   ) Print("	ERR_SOME_OBJECT_ERROR	Some error in object operation.	");

   return(0);


  }
//Stops after some pips go in the opposite direction

void TrailingStop()
  {

   if(OrderSelect(ticket,SELECT_BY_TICKET,MODE_TRADES)==true)
     {
      if(TSonce==1)StopPrice=OrderOpenPrice();TSonce=0;//This must be executed only once per order
      if(OrderType()==OP_BUY)
        {
         if(StopPrice<Ask)
           {
            StopPrice=Ask;
           }
         else if(StopPrice-Ask>0 && (StopPrice-Ask)>PipStop)
           {
            //close
            if((OrderClose(ticket,LotSize,Bid,3,clrGreenYellow))==true) //select by pos is 0-the first order to have opened,1- the seocnd order,2-the 3rd order
              {                                                     //so to solveth problem you need { orderstotal()-1    } while cheking if { !=-1 }
               Print("Order closed in trailstop");
               //open sell only if orderclose succeeded

               RefreshRates();
               //open opposite
               OpenSell();
               TSonce=1;
              }
            else
              {
               Print("OrderClose failed on tick1:",GetLastError(),ErrorDesc(GetLastError()));
              }

           }
        }
      else if(OrderType()==OP_SELL)
        {
         if(TSonce==1)StopPrice=OrderOpenPrice();TSonce=0;//This must be executed only once per order
         if(StopPrice>Bid)
           {
            StopPrice=Bid;
           }
         else if(StopPrice-Bid<0 && MathAbs((StopPrice-Bid))>PipStop)
           {
            //close
            if((OrderClose(ticket,LotSize,Ask,3,clrGreenYellow))==true) //maybe i need to put the orderticket into a vari ////holy fuck its actually working the orderclose i mean
               // able int order_id==orderticket(); and the 
               //order id must be saved in the opensell and buy func
              {
               Print("Order closed");

               RefreshRates();
               //open opposite
               OpenBuy();
               TSonce=1;
              }
            else
              {
               Print("OrderClose failed on tick 2:",GetLastError(),ErrorDesc(GetLastError()));
              }

           }
        }
     }
   else Print("error in trailing stop select order:",GetLastError(),ErrorDesc(GetLastError()));

   return;
  }
//--------Closes order if loss begins aaccordng to MA
void TrailingStopCloseOnMA()
  {
   double MA=iMA(Symbol(),MAtimeframe,period,MAshift,MAmethod,AppliedPrice,MaBuffershift);
   if(OrderSelect(ticket,SELECT_BY_TICKET,MODE_TRADES)==true)
     {
      if(TSonce==1)StopPrice=MA;TSonce=0;//This must be executed only once per order
      if(OrderType()==OP_BUY)
        {
         if(StopPrice<MA)
           {
            StopPrice=MA;
           }
         else if(StopPrice-MA>0 && (StopPrice-MA)>PipStop)
           {
            //close
            if((OrderClose(ticket,LotSize,Bid,3,clrGreenYellow))==true) //select by pos is 0-the first order to have opened,1- the seocnd order,2-the 3rd order
              {                                                     //so to solveth problem you need { orderstotal()-1    } while cheking if { !=-1 }
               Print("Order closed in trailstop");
               //open sell only if orderclose succeeded

               RefreshRates();
               //open opposite

               TSonce=1;
              }
            else
              {
               Print("OrderClose failed on tick1:",GetLastError(),ErrorDesc(GetLastError()));
              }

           }
        }
      else if(OrderType()==OP_SELL)
        {
         if(TSonce==1)StopPrice=MA;TSonce=0;//This must be executed only once per order
         if(StopPrice>MA)
           {
            StopPrice=MA;
           }
         else if(StopPrice-MA<0 && MathAbs((StopPrice-MA))>PipStop)
           {
            //close
            if((OrderClose(ticket,LotSize,Ask,3,clrGreenYellow))==true) //maybe i need to put the orderticket into a vari ////holy fuck its actually working the orderclose i mean
               // able int order_id==orderticket(); and the 
               //order id must be saved in the opensell and buy func
              {
               Print("Order closed");

               RefreshRates();
               //open opposite

               TSonce=1;
              }
            else
              {
               Print("OrderClose failed on tick 2:",GetLastError(),ErrorDesc(GetLastError()));
              }

           }
        }
     }
   else Print("error in trailing stop select order:",GetLastError(),ErrorDesc(GetLastError()));

   return;
  }
//--------Closes open position if lose begins---
void TrailingStopCloseOnPrice()
  {

   if(OrderSelect(ticket,SELECT_BY_TICKET,MODE_TRADES)==true)
     {
      if(TSonce==1)StopPrice=Ask;TSonce=0;//This must be executed only once per order
      if(OrderType()==OP_BUY)
        {
         if(StopPrice<Ask)
           {
            StopPrice=Ask;
           }
         else if(StopPrice-Ask>0 && (StopPrice-Ask)>PipStop)
           {
            //close
            if((OrderClose(ticket,LotSize,Bid,3,clrGreenYellow))==true) //select by pos is 0-the first order to have opened,1- the seocnd order,2-the 3rd order
              {                                                     //so to solveth problem you need { orderstotal()-1    } while cheking if { !=-1 }
               Print("Order closed in trailstop");
               //open sell only if orderclose succeeded

               RefreshRates();
               //open opposite

               TSonce=1;
              }
            else
              {
               Print("OrderClose failed on tick1:",GetLastError(),ErrorDesc(GetLastError()));
              }

           }
        }
      else if(OrderType()==OP_SELL)
        {
         if(TSonce==1)StopPrice=Ask;TSonce=0;//This must be executed only once per order
         if(StopPrice>Ask)
           {
            StopPrice=Ask;
           }
         else if(StopPrice-Ask<0 && MathAbs((StopPrice-Ask))>PipStop)
           {
            //close
            if((OrderClose(ticket,LotSize,Ask,3,clrGreenYellow))==true) //maybe i need to put the orderticket into a vari ////holy fuck its actually working the orderclose i mean
               // able int order_id==orderticket(); and the 
               //order id must be saved in the opensell and buy func
              {
               Print("Order closed");

               RefreshRates();
               //open opposite

               TSonce=1;
              }
            else
              {
               Print("OrderClose failed on tick 2:",GetLastError(),ErrorDesc(GetLastError()));
              }

           }
        }
     }
   else Print("error in trailing stop select order:",GetLastError(),ErrorDesc(GetLastError()));

   return;
  }
//+------------------------------------------------------------------+
//|                                                                  |
//+------------------------------------------------------------------+
//----Calculates LotSize by percent od risk by FreeMargin.
bool LotAdjust()
  {
   LotSize=NormalizeDouble(
                           (Risk*AccountBalance()*AccountLeverage())/
                           (100*MarketInfo(Symbol(),MODE_LOTSIZE))
                           ,3
                           );
   if(LotSize<0.01)LotSize=0.01;
   return(true);
  }
//----open buy if no orders are open

void OpenBuy()
  {
   if(CheckOnEveryOpenOrder==true)
     {                  //opens new buy order if no orders are open
      if(OrdersTotal()==0)
        {
         if(LotAdjust()==true)
           {
            ticket=OrderSend(Symbol(),OP_BUY,LotSize,Ask,3,0,0,"Buy",0,00,Blue);
           }
         else
           {
            Alert("Error in LotAdjust Buy",GetLastError(),ErrorDesc(GetLastError()));
           }
         if(ticket>-1) //send buy
           {
            Comment("Opened",OrderType(),"order",magic,"at:",Ask); //show type of order and price
            text=StringConcatenate("Opened",OrderType(),"order",magic,",ticket:",ticket,",at:",Ask);

            SendNotification(text);
            magic++;

           }
         else Print("OrderSend failed",GetLastError(),ErrorDesc(GetLastError()));
        }
     }
   else
     {
      if(LotAdjust()==true)
        {
         ticket=OrderSend(Symbol(),OP_BUY,LotSize,Ask,3,0,0,"Buy",0,00,Blue);
        }
      else
        {
         Alert("Error in LotAdjust Buy",GetLastError(),ErrorDesc(GetLastError()));
        }
      if(ticket>-1) //send buy
        {
         Comment("Opened",OrderType(),"order",magic,"at:",Ask);                                          //show type of order and price
         text=StringConcatenate("Opened",OrderType(),"order",magic,",ticket:",ticket,",at:",Ask);

         SendNotification(text);
         magic++;

        }
      else Print("OrderSend failed",GetLastError(),ErrorDesc(GetLastError()));
     }
   return;
  }
//opens new sell order if no orders are open
void OpenSell()
  {
   if(CheckOnEveryOpenOrder==true)
     {                  //opens new buy order if no orders are open
      if(OrdersTotal()==0)
        {
         if(LotAdjust()==true)
           {
            ticket=(OrderSend(Symbol(),OP_SELL,LotSize,Bid,3,0,0,"Buy",0,00,Red));
           }
         else
           {
            Alert("Error in LotAdjust sell",GetLastError(),ErrorDesc(GetLastError()));
           }
         if(ticket>-1) //send buy
           {
            Comment("Opened",OrderType(),"order",magic,"at:",Bid);
            text=StringConcatenate("Opened",OrderType(),"order",magic,",ticket:",ticket,",at:",Bid);

            SendNotification(text);                                       //show type of order and price

            magic++;

           }
         else Print(GetLastError(),ErrorDesc(GetLastError()));
        }
     }
   else
     {
      if(LotAdjust()==true)
        {
         ticket=(OrderSend(Symbol(),OP_SELL,LotSize,Bid,3,0,0,"Buy",0,00,Red));
        }
      else
        {
         Alert("Error in LotAdjust sell",GetLastError(),ErrorDesc(GetLastError()));
        }
      if(ticket>-1) //send buy
        {
         Comment("Opened",OrderType(),"order",magic,"at:",Bid);                                          //show type of order and price
         text=StringConcatenate("Opened",OrderType(),"order",magic,",ticket:",ticket,"at:",Bid);

         SendNotification(text);
         magic++;

        }
      else Print(GetLastError(),ErrorDesc(GetLastError()));
     }
   return;
  }
