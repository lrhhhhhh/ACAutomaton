class Solution {
public:
    string maximumTime(string time) {
        if(time[0] == '?'){
            if(time[1] == '?'){
                time[0] = '2';
                time[1] = '3';
            }
            else if(time[1]-'0' > 3){
                time[0] = '1';
            }
            else{
                time[0] = '2';
            }
        }
        if(time[1] == '?'){
            if(time[0] == '2'){
                time[1] = '3';
            }
            else{
                time[1] = '9';
            }
        }
        time[3] = time[3]=='?'?'5':time[3];
        time[4] = time[4]=='?'?'9':time[4];
        return time;
    }                                                                                
};