    
    #include <vector>
    #include <iostream>

    using namespace std;
    int main()
    {
        //이름과 나이 몸무게 입력 17세 이상이거나 80kg 이상이면 성인부 아니면 청소년부로 출력 
        vector<int> age;
        vector<int> weight;
        vector<string> name;


        int ageTmp;
        int weightTmp;
        string nameTmp;

        do {
            cin >> nameTmp >> ageTmp >> weightTmp;
            if (nameTmp == "#" && ageTmp == 0 && weightTmp == 0) {
                break;
            }
            age.push_back(ageTmp);
            weight.push_back(weightTmp);
            name.push_back(nameTmp);




        } while (1);

        for (int i = 0; i < age.size(); i++) {
            if (age[i] > 17 || weight[i] >= 80) {
                cout << name[i] << " " << "Senior" << "\n";

            }
            else {
                cout << name[i] << " " << "Junior" << "\n";

            }


        }



        return 0;
    }
