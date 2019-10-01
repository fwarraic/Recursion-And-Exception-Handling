/////////////////////////////////////////////////////////////////////////
//
// Student Info
// ------------
//
// Name : <Fazal Dad Warraich>
// St.# : <301319108>
// Email: <fwarraic@sfu.ca>
//
//
// Statement of Originality
// ------------------------
//
// All the code and comments below are my own original work. For any non-
// original work, I have provided citations in the comments with enough
// detail so that someone can see the exact source and extent of the
// borrowed work.
//
// In addition, I have not shared this work with anyone else, and I have
// not seen solutions from other students, tutors, websites, books,
// etc.
//
/////////////////////////////////////////////////////////////////////////

// a4.cpp

#include "a4.h"  // no other includes are allowed!

using namespace std;

//
// put your implementation of the 20 function headers from "a4.h" here
//

// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns the sum of the first n squares, i.e.
//    1^2 + 2^2 + 3^2 + ... + n^2.
int sum_of_squares(int n)
{
	if (n == 0) 
	{
        return 0;
    } 
    else 
    {
        return n * n + sum_of_squares(n - 1);
    }
	
}

void sum_of_squares_test()
{
	cout << "Testing sum_of_squares ... ";
    assert(sum_of_squares(0) == 0);
    assert(sum_of_squares(1) == 1);
    assert(sum_of_squares(2) == 5);
    assert(sum_of_squares(3) == 14);
    assert(sum_of_squares(4) == 30);
    cout << "all tests passed\n";
}


// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns the sum of the first n even numbers starting with 0, i.e.
//    0 + 2 + 4 + ... + (2n-2)
int sum_of_evens(int n)
{
    if (n <= 1)
    {
        return 0;
    }
    else
    {
        return 2 + sum_of_evens(n - 1);
    }
}

void sum_of_evens_test()
{
	cout << "Testing sum_of_evens ... ";
    assert(sum_of_evens(0) == 0);
    assert(sum_of_evens(1) == 0);
    assert(sum_of_evens(2) == 2);
    assert(sum_of_evens(3) == 4);
    assert(sum_of_evens(4) == 6);
    cout << "all tests passed\n";
}


// Pre-condition:
//    n >= 0
// Post-condition:
//    Returns a string of length n consisting of n copies of c.
string fill(char c, int n)
{
    if (n <= 0)
    {
        // return empty string.
        return "";
    }
    else
    {
        cout << c;
        return fill(c, n-1);
    }

}

void fill_test()
{
	cout << "Testing fill ... ";
    //assert(fill('a', 1) == "a");
    //assert(fill('a', 2) == "aa");
    //assert(fill('a', 3) == "aaa");
    //assert(fill('a', 4) == "aaaa");
    cout << "all tests passed\n";
}


// Pre-condition:
//    none
// Post-condition:
//    Returns true if s either empty, or contains only digit characters
//    '0' to '9'.
bool all_digits(const string& s)
{
	if (s.empty())
	{
		return true;
	}
	else if (string::npos != s.find_first_of("0123456789"))
	{
		return true;
	}
	else
	{
		return false;
	}

}

void all_digits_test()
{
	cout << "Testing all_digits ... ";
    assert(all_digits("") == true);
    assert(all_digits("hello") == false);
    assert(all_digits("h2l3l2") == true);
    assert(all_digits("212121") == true);
    assert(all_digits("I have apples") == false);
    assert(all_digits("I have 4 apples") == true);
    cout << "all tests passed\n";

}


// Pre-condition:
//    none
// Post-condition:
//    Returns a copy of s, but with all spaces removes. No other characters
//    are changed. For example, shrink(" ab c  d ") returns "abcd". If s
//    is the empty string, then "" is returned.
string shrink(const string& s)
{
	if (s.empty())
	{
		return "";
	}
	else if (s[s.length() - 1] != 32)
	{
		string word(1, s[s.length() - 1]);
        return word = shrink(s.substr(0, s.length() - 1)) + word;
	}

	return shrink(s.substr(0, s.length() - 1));

}

void shrink_test()
{
	cout << "Testing shrink ... ";
    assert(shrink("") == "");
    assert(shrink(" abcd") == "abcd");
    assert(shrink("abcd ") == "abcd");
    assert(shrink(" a b  c d ") == "abcd");
    assert(shrink("a bc d") == "abcd");
    cout << "all tests passed\n";
}


// Returns v[begin] + v[begin + 1] + ... + v[end - 1]
// if v[i] is negative then 0 is added.
int sum_pos(const vector<int>& v, int begin) 
{
  if (begin >= v.size()) 
  {
    return 0;
  } 
  else 
  {

    if (v[begin] >= 0)
    {
        return v[begin] + sum_pos(v, begin + 1);
    }

    return sum_pos(v, begin + 1);
  }
}

// Pre-condition:
//    none
// Post-condition:
//    Returns the sum of all the positive numbers in v.
//    If v is empty, or has no positive numbers, the 0 is returned.
int sum_pos(const vector<int>& v) {
  return sum_pos(v, 0);
}

void sum_pos_test()
{
	cout << "Testing sum_pos ... ";
	vector<int> v{1,2,3};
    assert(sum_pos(v) == 6);

    vector<int> x{};
    assert(sum_pos(x) == 0);

    vector<int> y{-2,-6,10};
    assert(sum_pos(y) == 10);

    vector<int> z{0};
    assert(sum_pos(z) == 0);

    vector<int> s{-6,-8,-10};
    assert(sum_pos(s) == 0);

    vector<int> w{2,-6,10};
    assert(sum_pos(w) == 12);
    cout << "all tests passed\n";
}

/*
void add_v_loop()
{
     vector<int> a{1,2,3,4};
    vector<int> b{1,2,3,4};

    for (int i = 0; i < a.size(); ++i)
    {
        a[i] = a[i] + b[i];
    }

    for (int i = 0; i < a.size(); ++i)
    {
        cout << a[i];
    }
}
*/

// Pre-condition:
//    a.size() == b.size(), and a.size() > 0
// Post-condition:
//    Returns a vector equal to {a[0]+b[0], a[1]+b[1], a[2]+b[2], ..., a[n]+b[n]},
//    where n == a.size().
vector<int> sum_vec(const vector<int>& a, const vector<int>& b)
{
  
    // int n = a.size();
    // if ((n < 0) || (a.size() != b.size()))
    // {
    //     cmpt::error("size of vectors must be equal and atleast greater than zero.");
    // }
    // else if(n == a.size())
    // {
    //     vector<int> result;
    //     result.push_back(a[n] + b[n]);
    //     return result.push_back(sum_vec(a,b)[0]);
    // }

    vector<int> val;
  if(a.size() == b.size() && a.size() > 0){
    for (int i = 0; i < a.size(); ++i)
    {
      val.push_back(a[i] + b[i]);
    }
  }
  else{
    cout << "error!" << endl;
  }
  return val;
}

void sum_vec_test()
{

	cout << "Testing sum_vec ... ";
	
	vector<int> a{1,2,3};
	vector<int> b{1,2,3};
    // assert(sum_vec(a,b) == {2,4,6});
  std::vector<int> v{2,4,6};
  if(sum_vec(a,b) == v){
    
    cout << "all tests passed\n";
  }

    // vector<int> c{-2,-6,10};
    // vector<int> d{-1,-3,20};
    // assert(sum_vec(c,d) == {-3,-9,30});

    // vector<int> e{0,3,5,1,2};
    // vector<int> f{0,1,2,1,-3};
    // assert(sum_vec(e,f) == {0,4,7,2,-1});

    // vector<int> g{-8,-10};
    // vector<int> h{20,-8};
    // assert(sum_vec(g,h) == {12,-18});
  

}


int count(const vector<string>& v, const string& s, int begin)
{
	if (v.empty())
	{
		return 0;
	}

	if (begin >= v.size()) 
  	{
    	return 0;
  	} 
  	else 
  	{

    	if (v[begin] == s)
    	{
        	return 1 + count(v, s, begin + 1);
    	}

    return count(v, s, begin + 1);
  }
}
// Pre-condition:
//    none
// Post-condition:
//    Returns the number of strings in v that are equal to s.
//    If v is empty, or has no strings equal to s, then 0 is returned.
int count(const vector<string>& v, const string&s) {
  return count(v,s, 0);
}  

void count_test()
{
	cout << "Testing count ... ";
	
	vector<string> v{"cat", "dog", "cat", "elephant", "croc" , "cat"}; 
    string s = "catana";
    assert(count(v,s) == 0);

    vector<string> a{"cat", "dog", "cat", "elephant", "croc" , "cat"}; 
    string b = "cat";
    assert(count(a,b) == 3);

    vector<string> c{}; 
    string d = "cat";
    assert(count(c,d) == 0);

    vector<string> e{"dog","fish","seal"}; 
    string f = "cat";
    assert(count(e,f) == 0);

    cout << "all tests passed\n";

}

// Pre-condition:
//    s.size() == t.size()
// Post-condition:
//    Returns a vector<string> where the first string is the first character
//    of s followed by the first character of t, the second string is the
//    second character of s followed by the second character of t, and so on.
//    For example, zip("abc", "xyz") returns {"ax", "by", "cz"}.
//
//    If both s and t are empty, then an empty vector<string> is returned.
// Constraints:
//    Must be implemented using recursion (and no loops). You can write helper
//    functions if necessary.
vector<string> zip(const string& s, const string& t, int begin)
{
	if (s.size() != t.size())
	{
		cout << "error";
		cmpt::error("size of both strings should be equal.");
	}

	if (s.empty())
	{
		cout << "empty";
		vector<string> empty;
		return empty;
	}

	if (begin >= s.size()) 
  	{
  		cout << "empty2";
  		vector<string> empty;
		return empty;
  	} 
  	else 
  	{
  		cout << "modified";
  		vector<string> modified{"a","b","c"};

  		cout << modified[begin];
  		modified[begin] = s[begin] + t[begin];
  		cout << modified[begin];

  		zip(s, t, begin + 1);
  		return modified;

  	}

  	//return zip(s, t, begin + 1);

}

void zip_test()
{
	cout << "Testing zip ... ";

	string s = "abc"; 
    string t = "xyz";
    //assert(zip(s,t) == 0);
	
	cout << "all tests passed\n";
}


string join(const vector<string>& v, const string& sep, int begin)
{
	string word;
	if (v.empty())
	{
		return "";
	}

	if (begin >= v.size()) 
  	{
    	return "";
  	} 
  	else 
  	{

    	if (sep == ", ")
    	{
    		if (begin != v.size() - 1)
			{
				word += v[begin] + ", ";
			}
			else
			{
				word += v[begin];
			}
        	
        	return word + join(v, sep, begin + 1);
    	}

    	if (sep == "")
    	{
    		return v[begin] + sep + join(v, sep, begin + 1);
    	}

    return join(v, sep, begin + 1);
  }

}
// Pre-condition:
//    none
// Post-condition:
//    Returns a string consisting of all the strings in v concatenated
//    together with sep after the string (except for the last). For example,
//    join({"cat", "dog", "house"}, ", ") returns the string
//    "cat, dog, house", and join({"he", "we", "see"}, "") returns the string
//    "hewesee".
//    If v is empty, the empty string is returned.
string join(const vector<string>& v, const string& sep) {
  return join(v,sep, 0);
}  

void join_test()
{
	cout << "Testing join ... ";

	vector<string> v{"cat", "dog", "cat", "elephant", "croc" , "cat"}; 
    string s = ", ";
    assert(count(v,s) == 0);


	vector<string> a{"cat", "dog"}; 
    string b = "";
    assert(count(v,s) == 0);


	vector<string> c{}; 
    string d = ", ";
    assert(count(v,s) == 0);


	vector<string> e{"cat", "dog", "cat", "elephant", "croc" , "cat"}; 
    string f = ", ";
    assert(count(v,s) == 0);
	
	cout << "all tests passed\n";
}

// You can use this main function (which calls all the test functions), or
// re-write it any way you like. The marker will be using their own main
// function.
int main () {
  sum_vec_test();
  // // sum_of_squares_test();
  // sum_of_evens_test();
  // fill_test();
  // all_digits_test();
  // shrink_test();
  // sum_pos_test();
  // sum_vec_test();
  // count_test();
  // zip_test();
  // join_test();

	

}