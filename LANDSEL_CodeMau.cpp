#include <iostream>
#include <cstdio>
#include <set>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long lli;
const int maxMN = 1e6;
int m, n, k;
int buffer[maxMN];
int* a[maxMN];
int base;

inline int Max(int i)
{
    return a[i][1];
}

void Enter()
{
    cin >> m >> n >> k;
    for (int j = 0; j < n; j++)
        a[j] = buffer + j * m;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> a[j][i];
    for (int i = 0; i < n; i++)
        sort(a[i], a[i] + m, [](int x, int y)
        {
            return x > y;
        });
}

void Init()
{
    base = 0;
    for (int i = 0; i < n; i++)
        base += a[i][0];
    for (int i = 0; i < n; i++)
    {
        for (int j = 1; j < m; j++)
            a[i][j] -= a[i][0];
        a[i][0] = 0;
    }
}

/*
Bảng A toàn số không dương, số đầu mỗi hàng = 0, cần chọn mỗi hàng 1 phần tử
Câu hỏi: Có thể chọn được k cách mà trọng số mỗi cách >= Threshold hay không
Bắt đầu với SetT = {T}, giới hạn T = Threshold cho n hàng
Sol: Mỗi giới hạn T với n hàng 0, 1, 2, ..., n - 1 quy về các giới hạn
     T - a[0][0], T - a[0][1], ..., T - a[0][m - 1] với n - 1 hàng từ 1 tới n - 1
- Giới hạn nào cho vào tập SetT cũng phải có ít nhất 1 kết quả (chỉ giữ những giá trị <= 0)
- Từ SetT với n lớp xây dựng SetT với n - 1 lớp (nếu SetT đủ k phần tử thì stop ngay)
- Vì a[0][0] = 0 => SetT với bài toán n - 1 lớp chứa hoàn toàn SetT với bài toán n lớp => chỉ bổ sung thêm

Từ SetT với n lớp => Xem sinh ra những T mới nào cho vào AddedT => SetT mới với n - 1 hàng ... => đủ k pt thì stop
Độ phức tạo O(kích thước bảng * log k)
*/
bool Count(int Threshold)
{
    typedef multiset<int>::iterator iter;
    if (Threshold > 0) return false;
    multiset<int> SetT;
    SetT.insert(Threshold);
    vector<int> AddedT;
    for (int i = 0; i < n; i++)
    {
        if (SetT.size() >= k) return true;
        AddedT.clear();
        for (int j = 1; j < m; j++) //Khi j = 0, a[i][0] = 0, các T mới = các T cũ, bỏ qua
        {
            iter Limit = SetT.upper_bound(a[i][j]);
            for (iter it = SetT.begin(); it != Limit; it++) //Xét các T trong SetT: T - a[i][j] <= 0
            {
                AddedT.push_back(*it - a[i][j]);
                if (AddedT.size() + SetT.size() >= k) return true;
            }
        }
        //Thêm những t mới vào SetT, những giá trị cũ vẫn giữ do nhận xét trên (a[i][0] == 0)
        for (int t: AddedT) SetT.insert(t);
    }
    return false;
}

int FindThreshold()
{
    int Low = 0, High = 0;
    for (int i = 0; i < n; i++)
        Low += a[i][m - 1];
    //Ngưỡng Low - 1 chắc chắn đủ K, ngưỡng High + 1 chắc chắn thiếu K
    while (Low <= High)
    {
        int Middle = (Low + High) / 2;
        if (Count(Middle))
            Low = Middle + 1;
        else
            High = Middle - 1;
    }
    return High;
}

/*
Bảng A toàn số không dương, số đầu mỗi hàng = 0, cần chọn mỗi hàng 1 phần tử
Xét các cách chọn có trọng số >= Threshold
Cần biết: Tổng trọng số và số lượng của chúng
Làm như trên, quan tâm đến SetT ở bước cuối, mỗi giá trị t trong SetT ứng với một phương án
Để ý rằng mỗi t ở SetT sẽ bằng Threshold trừ đi một loạt các a[][] đằng trước
nên trọng số phương án ứng với t chính là Threshold - t
*/
void GetSum(int Threshold, lli& Sum, int& q)
{
    typedef multiset<int>::iterator iter;
    Sum = 0; q = 0;
    if (Threshold > 0) return; //không có phương án nào thì tổng trọng số Sum = 0 và số phương án q = 0
    multiset<int> SetT;
    SetT.insert(Threshold);
    vector<int> AddedT;
    for (int i = 0; i < n; i++)
    {
        AddedT.clear();
        for (int j = 1; j < m; j++) //Khi j = 0, a[i][0] = 0, các T mới = các T cũ, bỏ qua
        {
            iter Limit = SetT.upper_bound(a[i][j]);
            for (iter it = SetT.begin(); it != Limit; it++) //Xét các T trong SetT: T - a[i][j] <= 0
                AddedT.push_back(*it - a[i][j]);
        }
        //Thêm những t mới vào SetT, những giá trị cũ vẫn giữ do nhận xét trên (a[i][0] == 0)
        for (int t: AddedT) SetT.insert(t);
    }
    Sum = 0;
    for (int t: SetT) Sum += Threshold - t; //phương án ứng với t có trọng số = Threshold - t
    q = SetT.size();
}

void Solve()
{
    int Threshold = FindThreshold(); //Số cách chọn trọng số là Threshold + 1 < k <= Số cách chọn với trọng số là Threshold)
    lli res;
    int q;cout << Threshold << endl ;
    GetSum(Threshold + 1, res, q); //Chọn q cách có trọng số > Threshold với tổng trọng số == res
    //Còn thiếu cách nào thì cách đó có trọng số = Threshold
    res += lli(k - q) * Threshold;
    res += lli(base) * k; //mỗi phương án cộng thêm base cho khớp với dữ liệu ban đầu
    cout << res;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LANDSEL.inp", "r", stdin);
    //freopen("LANDSEL.out", "w", stdout);

    Enter();
    Init();
    Solve();
}
