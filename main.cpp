// kyrsovaya.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <string>
#include <vector>


using namespace std;
int kol_i = 0;






void print_vector(const vector<int>& vec, string sep = " ")
{
    for (auto elem : vec)
    {
        cout << elem << sep;
    }
   cout << std::endl;
}


vector<int> naivni(string str, string b) 
{
    kol_i = 0;
    vector<int> ans;
     
       
    for (int i = 0; i < str.length() - (b.length()-1) ; i++) {
       
        //cout <<i;
        for (int j = 0; j < b.length() ; j++) {
            kol_i++;
            if (str[i + j] != b[j]) { break; }
            if (j == b.length()-1) { ans.push_back(i+1);  // cout << "\n" << i+1 << "\n";
            }
        }
    }
  
   // cout << "\n" << b.length() << "\n";
   // cout << "\n" << str.length() << "\n";

    
    return ans;
}

vector<int> algoritm2(string str, string b)
{
    kol_i = 0;
    vector<int> ans;
    int sh = -1;
    int sh_con = -1;
    int m = b.length() + 1;
   cout << "\n";
    int *mas = new int[m];
    mas[m-1] = m-1;
   
    for (int i = m-2;  i >= 0; i--)
    {
        
        for (int j = i; j < b.length()-1; j++) { if (b[i] == b[j]) sh = j; }
        if (b[i] == b[m - 2]) { mas[m - 2] = m - 2 - sh;
        }
        mas[i] = m-2-sh;
       // cout << b[i];
    }
   
  
   cout << b;
   cout << "\n";

    
    for (int i = 0; i < m; i++)
    {
        
        cout << mas[i];
        cout << "|";
    }
    cout << "\n";
  
  
     
    if (str.length() < b.length()) {
        return ans;
    }
    
    else {
        int in = -1;
        int i = b.length() - 1;
        int k =  b.length() - 1;
       
        while (i < str.length() ) {
            for (int j =i; j >= i - (m - 2); j--) {
                kol_i++;
                if (str[i] != b[b.length() - 1]) {
                    for (int jj = 0; jj < m - 2; jj++) { 
                        if (str[i] == b[jj]) in = jj;  
                    }
                    if (in > -1) {
                        i += mas[in]; break;
                    }
                    else { i += mas[m - 1]; break; }
                }
                if (str[j] == b[k - (i - j)]) {
                    in = k - (i - j);
                }
                else { i += mas[k - (i - j)]; break; }

                if (in == 0) { ans.push_back(j + 1); i +=1; break; }
                }
            
            }
         
        }
    
   // cout << "\n" << b.length() << "\n";
   // cout << "\n" << str.length() << "\n";
    
   
   
    return ans;
}



int main()
{
    setlocale(LC_ALL, "Russian");
    int var=0;//    0123456789012345678901234567890
    string str = "C++, Laboratories high-level computer programming language. Developed by Bjarne Stroustrup of Bell Laboratories in the early 1980s, it is based on the traditional C language but with added object-oriented programming and other capabilities. C++, along with Java, has become popular for developing commercial software packages that incorporate multiple interrelated applications. C++ is considered one of the fastest languages and is very close to low-level languages, thus allowing complete control over memory allocation and management. This very feature and its many other capabilities also make it one of the most difficult languages to learn and handle on a large scale.C++, high-level computer programming language. Developed by Bjarne Stroustrup of Bell Laboratories in the early 1980s, it is based on the traditional C language but with added object-oriented programming and other capabilities. C++, along with Java, has become popular for developing commercial software packages that incorporate multiple interrelated applications. C++ is considered one of the fastest languages and is very close to low-level languages, thus allowing complete control over memory allocation and management. This very feature and its many other capabilities also make it one of the most difficult languages to learn and handle on a large scale.C++, high-level computer programming language. Developed by Bjarne Stroustrup of Bell Laboratories in the early 1980s, it is based on the traditional C language but with added object-oriented programming and other capabilities. C++, along with Java, has become popular for developing commercial software packages that incorporate multiple interrelated applications. C++ is considered one of the fastest languages and is very close to low-level languages, thus allowing complete control over memory allocation and management. This very feature and its many other capabilities also make it one of the most difficult languages to learn and handle on a large scale.C++, high-level computer programming language. Developed by Bjarne Stroustrup of Bell Laboratories in the early 1980s, it is based on the traditional C language but with added object-oriented programming and other capabilities. C++, along with Java, has become popular for developing commercial software packages that incorporate multiple interrelated applications. C++ is considered one of the fastest languages and is very close to low-level languages, thus allowing complete control over memory allocation and management. This very feature and its many other capabilities also make it one of the most difficult languages to learn and handle on a large scale.";
    string b ="capabilities also make it one of the most difficult languages to learn and handle on a large scale";
    vector<int> ans;



    while (true) {
        cout << "\n1.Ввод строки и подстроки\n"
            << "2.Наивный алгоритм поиска\n"
            << "3.Алгоритм Бойера — Мура — Хорспула\n"
            << "4.Отчет\n"
            << "5.Выход\n";
        cout << "\nВыберите пункт меню: ";
        cin >> var;

        switch (var) {
        case 1:
            cout << "\nВведите строку:";
            cin >> str;
            cout << "\nВведите подстроку:";
            cin >> b;
            if (str=="" || b=="") var=1;
            else break;
        case 2:
            cout << "\n-----------------------------------------\nНаивный алгоритм поиска\n";
            cout << "Строка: " << str << "\n" << "Подстрока: " << b << "\n";
         
            ans = naivni(str, b);
            
          
            if (ans.empty() == false) {
                cout << "Подстрока найдена в: ";
                print_vector(ans, "; ");
            }
            else
            {
                cout << "\nПодстрока не найдена. \n";
            }
            break;
        case 3:
            cout << "\n-----------------------------------------\nАлгоритм Бойера — Мура — Хорспула\n";
             cout << "Строка: " << str << "\n" << "Подстрока: " << b << "\n";
            cout << "Таблица смещения";
          
            //cout << b[m-2];
        
            ans = algoritm2(str, b);
           
            if (ans.empty() == false) {
                cout << "Подстрока найдена в: ";
                print_vector(ans, "; ");
            }
            else
            {
                cout << "Подстрока не найдена. \n";
            }
           
            break;
        case 4:
            cout << "\n-----------------------------------------\nНаивный алгоритм поиска\n\n";
            cout << "Строка: " << str << "\n" << "Подстрока: " << b << "\n";
            cout << "\n";
           
            ans = naivni(str, b);
            if (ans.empty() == false) {
                cout << "Подстрока найдена в: ";
                print_vector(ans, "; ");
            }
            else
            {
                cout << "\nПодстрока не найдена.\n ";
            }
           
          
            cout << "Количество итераций:" << kol_i << "\n";
            cout << "\n-----------------------------------------\n";

            cout << "\n-----------------------------------------\nАлгоритм Бойера — Мура — Хорспула\n";
            cout << "Строка: " << str << "\n" << "Подстрока: " << b << "\n";
            cout << "Таблица смещения ";
            //cout << b[m-2];
          

           
            ans = algoritm2(str, b);
            if (ans.empty() == false) {
                cout << "Подстрока найдена в: ";
                print_vector(ans, "; ");
            }
            else
            {
                cout << "\nПодстрока не найдена. \n";
            }
            
           
      
           
            cout << "Количество итераций:" << kol_i << "\n";
            cout << "\n-----------------------------------------\n";
            break;
        case 5:
            
            return 0;
            break;
        default: 
        break;
        }

    }
    
return 0;

}

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
