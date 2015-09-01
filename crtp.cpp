/*CRTP stands for Curious Recurring Template Pattern
 This code implements two differents ways to achieve 
 polymorphism: first is through CRTP and the second one
 uses virtual functions.
*/

#include <iostream>

using namespace std;

template<class Derived>
class BaseT
{
public:
	BaseT(){};
	void base_interface(){
		 static_cast<Derived*>(this)->derived_function();//or define derived_function as static
	}

private:

};


class Derived_T_A : public BaseT<Derived_T_A>{

public:
	//Derived_T_A():BaseT<Derived_T_A>(){}
	void derived_function(){
		cout<<"This is derived_function in class A"<<endl;
	}
};

class Derived_T_B : public BaseT<Derived_T_B>{

public:
	//Derived_T_B(const int &init):BaseT<Derived_T_B>(init){}
	void derived_function(){
		cout<<"This is derived_function in class B"<<endl;
	}
};

class BaseV
{

public:
	BaseV(const int &init):foo(init){};
	virtual void derived_function() = 0;//
private:
int foo;

};


class Derived_A_V : public BaseV{

public:
	Derived_A_V(const int &init):BaseV(init){}
	void derived_function(){
		cout<<"This is derived_function in A, virtual call"<<endl;
	}

};

class Derived_B_V : public BaseV{

public:
	Derived_B_V(const int &init):BaseV(init){}
	void derived_function(){
		cout<<"This is derived_function in class B, virtual call"<<endl;
	}
};

//************************

int main()
{
	BaseT<Derived_T_A> * instance_of_A = new Derived_T_A;
	instance_of_A->base_interface();

	BaseT<Derived_T_B> * instance_of_B = new Derived_T_B;
	instance_of_B->base_interface();

	BaseV * instance_of_A_V = new Derived_A_V();
	instance_of_A_V->derived_function();

	BaseV * instance_of_B_V = new Derived_B_V();
	instance_of_B_V->derived_function();

    	return 0;
}
