/*****************************************************************************
 VBase Copyright (c) 2015. All Rights Reserved.

 FileName: reference_base.h
 Version: 1.0
 Date: 2015.3.8

 History:
 jeffguo     2015.3.8   1.0     Create
 ******************************************************************************/

#ifndef __VBASE_REFERENCE_BASE_H__
#define __VBASE_REFERENCE_BASE_H__

#include <stdio.h>

namespace base {

class reference_base
{
public:
	reference_base();
	virtual ~reference_base();

private:
    reference_base(const reference_base& x);
    reference_base& operator = (const reference_base& x);

public:
	virtual reference_base* retain();
	virtual void release();
	long retain_count() const;

private:
	volatile long ref_counter_;
};

template<class T>
class ref_adapter
	: public reference_base
{
public:
	explicit ref_adapter(T* pointer)
		: pointer_(pointer) {
	}

	virtual ~ref_adapter() {
		if (pointer_ != NULL) {
			delete pointer_;
			pointer_ = NULL;
		}
	}

	T* get() {
		return pointer_;
	}

public:
	T* pointer_;
};

} // end of namespace base
#endif
