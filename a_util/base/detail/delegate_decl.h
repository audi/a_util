/**
 * @file
 * Delegate declaration file
 *
 * @copyright
 * @verbatim
   Copyright @ 2017 Audi Electronics Venture GmbH. All rights reserved.

       This Source Code Form is subject to the terms of the Mozilla
       Public License, v. 2.0. If a copy of the MPL was not distributed
       with this file, You can obtain one at https://mozilla.org/MPL/2.0/.

   If it is not possible or desirable to put the notice in a particular file, then
   You may include the notice in a location (such as a LICENSE file in a
   relevant directory) where a recipient would be likely to look for such a notice.

   You may add additional accurate notices of copyright ownership.
   @endverbatim
*/

#ifndef A_UTIL_UTIL_DELEGATE_DECL_HEADER_INCLUDED
#define A_UTIL_UTIL_DELEGATE_DECL_HEADER_INCLUDED

namespace a_util
{
namespace detail
{
/// Contains delegate base class and types for delegates
namespace delegates
{
template <typename ReturnType>
class DelegateInterface
{
public:
    virtual ~DelegateInterface();
    virtual ReturnType invoke() = 0;
    virtual DelegateInterface<ReturnType>* clone() = 0;
};

template <typename ReturnType>
class FunctionDelegate : public DelegateInterface<ReturnType>
{
    typedef ReturnType (*Function)();

public:
    FunctionDelegate(Function f);
    virtual ReturnType invoke();
    virtual DelegateInterface<ReturnType>* clone();

private:
    Function _func;
};

template <typename ReturnType, typename Method, typename Instance>
class MethodDelegate : public DelegateInterface<ReturnType>
{
public:
    MethodDelegate(Method method, Instance& instance);
    virtual ReturnType invoke();
    virtual DelegateInterface<ReturnType>* clone();

private:
    Method _method;
    Instance& _instance;
};
} // namespace delegates

/// Contains delegate base class and types for functions
namespace functions
{

template <typename ReturnType, typename ParamType>
class DelegateInterface
{
public:
    virtual ~DelegateInterface();
    virtual ReturnType invoke(ParamType) = 0;
    virtual DelegateInterface<ReturnType, ParamType>* clone() = 0;
};

template <typename ReturnType, typename ParamType>
class FunctionDelegate : public DelegateInterface<ReturnType, ParamType>
{
    typedef ReturnType (*Function)(ParamType);

public:
    FunctionDelegate(Function f);
    virtual ReturnType invoke(ParamType param);
    virtual DelegateInterface<ReturnType, ParamType>* clone();

private:
    Function _func;
};

template <typename ReturnType, typename ParamType, typename Method, typename Instance>
class MethodDelegate : public DelegateInterface<ReturnType, ParamType>
{
public:
    MethodDelegate(Method method, Instance& inst);
    virtual ReturnType invoke(ParamType param);
    virtual DelegateInterface<ReturnType, ParamType>* clone();

private:
    Method _method;
    Instance& _instance;
};

} // namespace functions

/// Base class for delegates and functions (manages the actual callee object)
template <typename DelegateType>
class DelegateBase
{
protected: // construction/destruction only available through specialized class
    ~DelegateBase();
    DelegateBase();
    DelegateBase(const DelegateBase& other);
    DelegateBase& operator=(const DelegateBase& other);

    void setDelegate(DelegateType* delegate);
    DelegateType* getDelegate();
    const DelegateType* getDelegate() const;

public:
    operator bool() const;

private:
    DelegateType* _ptr_to_callee;
};

} // namespace detail

/// For now, delegates are hidden in the experimental namespace
namespace experimental
{

/// general delegate template: encapsulates either a function or a method without a parameter
template <typename ReturnType>
class NullaryDelegate
    : public detail::DelegateBase<detail::delegates::DelegateInterface<ReturnType> >
{
public:
    /// Function constructor
    NullaryDelegate(ReturnType (*Function)());
    /// Method constructor
    template <typename Method, typename Instance>
    NullaryDelegate(Method method, Instance& instance);

    /// Invocation operator - invokes the method or function
    ReturnType operator()();

private:
    typedef detail::DelegateBase<detail::delegates::DelegateInterface<ReturnType> > Base;
};

/// general Function template: encapsulates either a function or a method with a single parameter
template <typename ReturnType, typename ParamType>
class UnaryDelegate
    : public detail::DelegateBase<detail::functions::DelegateInterface<ReturnType, ParamType> >
{
public:
    /// Function constructor
    UnaryDelegate(ReturnType (*Function)(ParamType));
    /// Method constructor
    template <typename Method, typename Instance>
    UnaryDelegate(Method method, Instance& instance);

    /// Invocation operator - invokes the method or function
    ReturnType operator()(ParamType param);

private:
    typedef detail::DelegateBase<detail::functions::DelegateInterface<ReturnType, ParamType> > Base;
};

} // namespace experimental
} // namespace a_util

#endif // A_UTIL_UTIL_DELEGATE_DECL_HEADER_INCLUDED
