//#pragma once
#pragma warning(disable : 4996)
//#include <queue>
//#include <iostream>
//#include <string>
//using namespace std;
//class clsQueueLine
//{
//private:
//	
//	short _TotalTickets=0;
//	string _PrefixQueue;
//	short servedClientsQueue=0;
//	short waitingClientsQueue;
//	short _ServingTimeQueue;
//
//	struct stTicket
//	{
//		string _PrefixTicket;
//		string _DateTime="";
//		short _ServingTime;
//		short _WaitedClients=0;
//	};
//
//	stTicket Ticket;
//
//	queue<stTicket> TicketsQueue;
//	queue<stTicket>TicketsQueueLTR;
//
//	string _IncrementPrefix()
//	{
//		return _PrefixQueue + to_string(_TotalTickets+1);
//	}
//
//	string _GetSystemDateTimeInString() {
//		time_t t = time(0);
//		tm* now = localtime(&t);
//
//		short Day, Month, Year, Hour, Minute, Second;
//
//		Year = now->tm_year + 1900;
//		Month = now->tm_mon + 1;
//		Day = now->tm_mday;
//		Hour = now->tm_hour;
//		Minute = now->tm_min;
//		Second = now->tm_sec;
//
//		return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - "
//			+ to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second)
//			);
//	}
//
//	short _GetWaitedClients()
//	{
//		return _TotalTickets == 0 ? 0 : _TotalTickets;
//	}
//
//	short _GetServingTime()
//	{
//		return _TotalTickets == 0 ? 0 : Ticket._ServingTime+_ServingTimeQueue;
//	}
//public:
//	clsQueueLine(string Prefix, short ServingTime)
//	{
//		_PrefixQueue = Prefix;
//		_ServingTimeQueue = ServingTime;
//	}
//	void IssueTicket()
//	{
//		Ticket._PrefixTicket = _IncrementPrefix();
//		Ticket._DateTime = _GetSystemDateTimeInString();
//		Ticket._WaitedClients = _GetWaitedClients();
//		Ticket._ServingTime = _GetServingTime();
//		TicketsQueue.push(Ticket);
//		_TotalTickets++;
//		waitingClientsQueue++;
//	}
//	void ServeNextClient()
//	{
//		if (!TicketsQueue.empty()) {
//			TicketsQueue.pop();
//		}
//		servedClientsQueue++;
//		waitingClientsQueue = _TotalTickets - servedClientsQueue;
//	}
//
//	void PrintInfo()
//	{
//		cout << "\n\t\t\t_________________________\t\t\t\n";
//		cout << "\n\t\t\t\tQueue Info";
//		cout << "\n\t\t\t_________________________\t\t\t\n";
//		cout << "\n\t\t\tPrefix: " << _PrefixQueue << "\n";
//		cout << "\t\t\tTotal Tickets: " << _TotalTickets << "\n";
//		cout << "\t\t\tServed Clients: " << servedClientsQueue << "\n";
//		cout << "\t\t\tWaited Clients: " << waitingClientsQueue << "\n";
//		cout << "\n\t\t\t________________________\t\t\t\n";
//	}
//
//	void PrintTicketsLineRTL() {
//		cout << "\n\t\t\tTickets: ";
//		queue<stTicket>TicketsQueueRTL = TicketsQueue;
//
//		while (!TicketsQueueRTL.empty())
//		{
//			cout << TicketsQueueRTL.front()._PrefixTicket << "<---";
//			TicketsQueueRTL.pop();
//		}
//		cout << endl;
//	}
//
//	void PrintTicketsLineLTR() {
//		cout << "\n\t\t\tTickets: ";
//		string *TicketsLineLTR = new string[_TotalTickets];
//		queue<stTicket>TicketsQueueLTR = TicketsQueue;
//
//		for (short i = 0; i < _TotalTickets; i++)
//		{
//			TicketsLineLTR[i] = TicketsQueueLTR.front()._PrefixTicket;
//			TicketsQueueLTR.pop();
//		}
//		for (short i = _TotalTickets-1; i >=0; i--)
//		{
//			cout << TicketsLineLTR[i]<< "--->";
//		}
//		delete[]TicketsLineLTR;
//		cout << endl;
//	}
//
//	void PrintAllTickets()
//	{
//		queue<stTicket>TicketsQueueTemp = TicketsQueue;
//		cout << "\n\t\t\t\t---Tickets---";
//		while (!TicketsQueueTemp.empty())
//		{
//			cout << "\n\t\t\t_________________________\t\t\t\n";
//			cout << "\n\t\t\t\t " << TicketsQueueTemp.front()._PrefixTicket << "\n";
//			cout << "\n\t\t\t" << TicketsQueueTemp.front()._DateTime << "\n";
//			cout << "\n\t\t\tWaiting Clients: " << TicketsQueueTemp.front()._WaitedClients << "\n";
//			cout << "\n\t\t\tServe Time in \n";
//			cout<< "\t\t\t"<<TicketsQueueTemp.front()._ServingTime << " minutes\n";
//			cout << "\n\t\t\t_________________________\t\t\t\n";
//			TicketsQueueTemp.pop();
//		}
//	}
//};
//

#pragma once
#pragma warning(disable : 4996)
#include <queue>
#include <stack>
#include <iostream>
#include <string>
using namespace std;
class clsQueueLine
{
private:
	short _TotalTickets = 0;
	short _ExpectedServeTime;
	string _Prefix = "";

	class clsTicket
	{
	private:
		short _Number = 0;
		string _TicketTime;
		string _Prefix;
		short _WaitingClients;
		short _ExpectedServeTime;

		string _GetSystemDateTimeInString() {
					time_t t = time(0);
					tm* now = localtime(&t);
			
					short Day, Month, Year, Hour, Minute, Second;
			
					Year = now->tm_year + 1900;
					Month = now->tm_mon + 1;
					Day = now->tm_mday;
					Hour = now->tm_hour;
					Minute = now->tm_min;
					Second = now->tm_sec;
			
					return (to_string(Day) + "/" + to_string(Month) + "/" + to_string(Year) + " - "
						+ to_string(Hour) + ":" + to_string(Minute) + ":" + to_string(Second)
						);
				}
	public:
		clsTicket(string Prefix,short Number,short WaitingClients,short ExpectedServeTime)
		{
			_Prefix = Prefix;
			_TicketTime = _GetSystemDateTimeInString();
			_Number = Number;
			_WaitingClients = WaitingClients;
			_ExpectedServeTime = ExpectedServeTime;
		}
		string FullNumber()
		{
			return _Prefix + to_string(_Number);
		}
		short ExpectedServeTime()
		{
			return _WaitingClients * _ExpectedServeTime;
		}
		void Print()
		{
			cout << "\n\t\t\t  _______________________\n";
			cout << "\n\t\t\t\t    " << FullNumber();
			cout << "\n\n\t\t\t    " << _TicketTime;
			cout << "\n\t\t\t    Wating Clients = " << _WaitingClients;
			cout << "\n\t\t\t      Serve Time In";
			cout << "\n\t\t\t       " << ExpectedServeTime() << " Minutes.";
			cout << "\n\t\t\t  _______________________\n";
		}
	};
public:

	queue <clsTicket> QueueLine;

	clsQueueLine(string Prefix, short ExpectedServeTime)
	{
		_Prefix = Prefix;
		_ExpectedServeTime = ExpectedServeTime;
		_TotalTickets = 0;
	}

	void IssueTicket()
	{
		_TotalTickets++;
		clsTicket Ticket(_Prefix, _TotalTickets, WaitingClients(), _ExpectedServeTime);
		QueueLine.push(Ticket);
	}

	short WaitingClients()
	{
		return QueueLine.size();
	}

	bool ServeNextClient()
	{
		if (QueueLine.empty())
		{
			return false;
		}
		QueueLine.pop();
		return true;
	}

	short ServedClients()
	{
		return _TotalTickets - WaitingClients();
	}
	void PrintInfo()
	{
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t\tQueue Info";
		cout << "\n\t\t\t _________________________\n";
		cout << "\n\t\t\t    Prefix   = " << _Prefix;
		cout << "\n\t\t\t    Total Tickets   = " << _TotalTickets;
		cout << "\n\t\t\t    Served Clients  = " << ServedClients();
		cout << "\n\t\t\t    Waiting Clients  = " << WaitingClients(); ;
		cout << "\n\t\t\t _________________________\n";
		cout << "\n";
	}
	void PrintTicketsLineRTL() {
		if (!QueueLine.empty())
		{
			cout << "\n\t\t\tTickets: ";
		}
		else
		{
			cout << "\n\t\t\tNo Tickets: ";
		}
		queue<clsTicket>TicketsQueueRTL = QueueLine;
		
		while (!TicketsQueueRTL.empty())
		{
			cout << TicketsQueueRTL.front().FullNumber() << "<---";
			TicketsQueueRTL.pop();
		}
		cout << endl;
	}
	void PrintTicketsLineLTR()
	{

		if (QueueLine.empty())
			cout << "\n\t\t\t No Tickets.";
		else
			cout << "\n\t\t\tTickets: ";  
		queue<clsTicket>tempQueueLine = QueueLine;
		stack<clsTicket>tempStackLine;
		while (!tempQueueLine.empty())
		{
			tempStackLine.push(tempQueueLine.front());
			tempQueueLine.pop();
		}
		while (!tempStackLine.empty())
		{
			cout << tempStackLine.top().FullNumber() << "--->";
			tempStackLine.pop();
		}
	}
	void PrintAllTickets()
	{

		cout << "\n\n\t\t\t       ---Tickets---";

		if (QueueLine.empty())
			cout << "\n\n\t\t\t     ---No Tickets---\n";
		queue<clsTicket>tempQueueLine = QueueLine;
		while (!tempQueueLine.empty())
		{
			tempQueueLine.front().Print();
			tempQueueLine.pop();
		}

	}
};