#include<iostream>
#include<iomanip> //For using setw(), setprecision(), ...
using namespace std;

int main(){
	double loan, rateperyear, payperyear;
	cout << "Enter initial loan: ";
	cin >> loan;
	cout << "Enter interest rate per year (%): ";
	cin >> rateperyear;
	cout << "Enter amount you can pay per year: ";
	cin >> payperyear;

	//use 'setw' to set width of table and 'left' to set left-alignment
	//you can change input argument of 'setw()' to see the effect
	//Try to change from 'left' to 'right' and see the effect
	// ใช้ 'setw' เพื่อกำหนดความกว้างของตาราง และ left เพื่อตั้งค่าการจัดชิดซ้าย
	// คุณสามารถเปลี่ยนอินพุตอาร์กิวเมนต์ของ 'setw()' เพื่อดูเอฟเฟกต์
	// ลองเปลี่ยนจาก 'ซ้าย' เป็น 'ขวา' แล้วดูผลลัพธ์

	double PrevBalance, Interest, Total, Payment, NewBalance;
	cout << setw(13) << left << "EndOfYear#"; 
	cout << setw(13) << left << "PrevBalance"; 
	cout << setw(13) << left << "Interest"; 
	cout << setw(13) << left << "Total";
	cout << setw(13) << left << "Payment";
	cout << setw(13) << left << "NewBalance";
	cout << "\n";
	
	//use 'fixed' and 'setprecision' to fix the number of decimal digits for displaying
	//you can change input argument of 'setprecision()' to see the effect
	//ใช้ 'fixed' และ 'setprecision' เพื่อกำหนดจำนวนหลักทศนิยมสำหรับการแสดง
	//คุณสามารถเปลี่ยนอินพุตอาร์กิวเมนต์ของ 'setprecision()' เพื่อดูเอฟเฟกต์

	PrevBalance = loan;
	for (int i = 0; i >= 0; i++)
	{	
		Interest = PrevBalance*(rateperyear/100); 
		Total = PrevBalance + Interest;
		Payment = payperyear;

		cout << fixed << setprecision(2); 
		cout << setw(13) << left << i+1; 
		cout << setw(13) << left << PrevBalance;
		cout << setw(13) << left << Interest;
		
		if(Total < Payment)Payment = Total;
		cout << setw(13) << left << Total;
		cout << setw(13) << left << Payment;

		NewBalance = Total - Payment;
		cout << setw(13) << left << NewBalance;
		cout << "\n";
		PrevBalance = NewBalance;
		if(NewBalance <= 0)break;
	}
	
	return 0;
}
