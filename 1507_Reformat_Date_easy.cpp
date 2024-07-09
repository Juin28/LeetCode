class Solution {
public:
    string reformatDate(string date) {
        int n = date.length();
        string year = date.substr(n - 4);

        unordered_map<string, string> month_map;
        month_map["Jan"] = "01";
        month_map["Feb"] = "02";
        month_map["Mar"] = "03";
        month_map["Apr"] = "04";
        month_map["May"] = "05";
        month_map["Jun"] = "06";
        month_map["Jul"] = "07";
        month_map["Aug"] = "08";
        month_map["Sep"] = "09";
        month_map["Oct"] = "10";
        month_map["Nov"] = "11";
        month_map["Dec"] = "12";
        string month = date.substr(n - 8, 3);
        month = month_map[month];
        
        string day = "0" + date.substr(0, 1);
        if (date[1] >= '0' && date[1] <= '9')
        {
            day.push_back(date[1]);
            day = day.substr(1, 2);
        }

        return year + '-' + month + '-' + day;
    }
};