// Given an encoded string, return it's decoded string.

// The encoding rule is: k[encoded_string], where the encoded_string inside the square brackets is being repeated exactly k times. Note that k is guaranteed to be a positive integer.

// You may assume that the input string is always valid; No extra white spaces, square brackets are well-formed, etc.

// Furthermore, you may assume that the original data does not contain any digits and that digits are only for those repeat numbers, k. For example, there won't be input like 3a or 2[4].

// Examples:

// s = "3[a]2[bc]", return "aaabcbc".
// s = "3[a2[c]]", return "accaccacc".
// s = "2[abc]3[cd]ef", return "abcabccdcdcdef".

class Solution {
public:
    string decodeString(string s) {
            int slen=s.size();
    int temp=0;
    int num;
    int i;
    string mul;
    stack<char> a;
    do{
        if(temp<slen) {
            a.push(s[temp]);
            temp++;
        }else break;
        if(a.top()==']'){
            a.pop();
            mul="";
            while(a.top()!='['){
                mul=mul+a.top();
                a.pop();
            }
            a.pop();
            i=0;
            num=0;

            while(!a.empty()&&a.top()>='0'&&a.top()<='9'){
                num=num+(a.top()-48)*pow(10,i);
                i++;
                a.pop();

            }
            if(num==0) num=1;

            std::reverse(mul.begin(), mul.end());
            cout << mul;
            for(int i=0;i<num;i++){
                for(int j=0;j<mul.size();j++){
                    a.push(mul[j]);
                }
            }
        }

    }while(1);
    string result="";

    while(!a.empty()){
        result=result+a.top();
        a.pop();
    }
    std::reverse(result.begin(), result.end());
    return result;
    }
};