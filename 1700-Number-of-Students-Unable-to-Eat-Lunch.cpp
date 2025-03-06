class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> studentQueue; 
    for (int student : students) {
        studentQueue.push(student);
    }

    int mismatchCount = 0;
    int sandwichIndex = 0; 
    while (!studentQueue.empty() && mismatchCount < studentQueue.size()) {
        if (studentQueue.front() == sandwiches[sandwichIndex]) {
            studentQueue.pop();   
            sandwichIndex++;       
            mismatchCount = 0;    
        } else {
            studentQueue.push(studentQueue.front());
            studentQueue.pop();
            mismatchCount++;        
        }
    }
    return studentQueue.size();
    }
};
