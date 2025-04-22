#include <iostream>
#include "clsQueueLine.h"
using namespace std;

int main()
{
	clsQueueLine PayBillsQueue("A0", 10);
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	PayBillsQueue.IssueTicket();
	cout << "\nPay Bills Queue Info\n";
	PayBillsQueue.PrintInfo();

	PayBillsQueue.PrintTicketsLineRTL();
	PayBillsQueue.PrintTicketsLineLTR();

	PayBillsQueue.PrintAllTickets();

	PayBillsQueue.ServeNextClient();
	//PayBillsQueue.ServeNextClient();
	cout << "\nPay Bills After Serving two client:\n";
	PayBillsQueue.PrintInfo();
	//system("pause>0");
	return 0;
}