#pragma once

#include <ostream>

class Ch8
{
public:
	Ch8();
	~Ch8();

	template<class Bi>
	void reverse_bi( Bi begin, Bi end )
	{
		while( end != begin )
		{
			end--;

			if( begin != end )
			{
				Ch8::swap( *begin, *end );

				begin++;
			}
		}
	}

	template<class T>
	static void swap( T & l, T & r )
	{
		T tmp = l;
		l = r;
		r = tmp;
	}

	template<class Ran, class X>
	bool binary_searcher( Ran begin, Ran end, const X& x )
	{
		if( ( x <=  *begin ) || ( x >= *( end - 1 ) ) )
			return false;

		while( begin < end )
		{
			Ran mid = begin + ( ( end - begin ) / 2 );

			if( x < *mid )
				end = mid;
			if( *mid < x )
				begin = mid + 1;
			else
				return true;
		}

		return false;
	}

	template<class T>
	void peek( const T & x )
	{

	}

	template<class T>
	void print_list( T begin, T end, std::ostream& output )
	{
		while( begin != end )
		{
			output << *begin++ << std::endl;
		}
	}

	template<class Input1, class Input2>
	bool equal( Input1 begin, Input1 end, Input2 begin2, Input2 end2 )
	{
		bool are_equal = true;

		while( begin != end )
		{
			if( begin2 == end2 )
			{
				are_equal = false;
				break;
			}
			
			are_equal &= *begin++ == *begin2++;

		}

		return are_equal;
	}

	template<class Input, class X>
	Input find( Input begin, Input end, const X& x )
	{
		while( begin != end )
		{
			if( *begin == x )
				 return begin;

			++begin;
		}

		return end;
	}

	template<class In, class Out>
	void copy( In begin, In end, Out d )
	{
		while( begin != end )
		{
			*d++ = *begin++;
		}
	}

	template<class Input, class X>
	X accumulate( Input begin, Input end, const X& x )
	{
		X result = X( x );

		while( begin != end )
		{
			result += *begin++;
		}

		return result;
	}

	/*
	Search range for subsequence
	Searches the range [first1,last1) for the first occurrence of the sequence defined by [first2,last2), and returns an iterator to its first element, or last1 if no occurrences are found.

	The elements in both ranges are compared sequentially using operator== (or pred, in version (2)): A subsequence of [first1,last1) is considered a match only when this is true for all the elements of [first2,last2).
	*/
	template<class FwdIter1, class FwdIter2>
	FwdIter1 search( FwdIter1 first1, FwdIter1 last1, FwdIter2 first2, FwdIter2 last2 )
	{
		if( first1 == last1 || first2 == last2 )
			return last1;

		FwdIter1 next = ( first1 + 1 );

		next++;
		/*
		while( first1 != last1 )
		{
			
		}
		*/

		return next;
	}

	template<class In, class UnaryPred>
	In partition( In begin, In end, UnaryPred pred ) const
	{
		In start = begin;

		while( begin != end )
		{
			if( pred( *begin ) )
			{
				*start++ = *begin;
			}

			++begin;
		}

		return start;
	}

	// to implement
	/*
	search
	find_if
	remove_copy
	remove_copy_if
	
	remove
	
	transform
	partition
	*/
};