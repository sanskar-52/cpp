    #include <iostream>
    using namespace std;

    string printme(){
        return "i am printme funciton";
    }
    string abc(string s){
        return s ;
    }

    int main()
    {
        {
            string&& ss = printme();
            cout << ss << endl;

            string hey = abc(ss);
            cout << hey << endl;

        }    


        return 0;
    }