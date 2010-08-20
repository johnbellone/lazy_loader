#ifndef INCLUDED_LAZY_LOADER_HPP
#define INCLUDED_LAZY_LOADER_HPP

/**
 * Copyright (C) 2010, John Bellone <jb@thunkbrightly.com>
 * 
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. Neither the name of the <organization> nor the
 *    names of its contributors may be used to endorse or promote products
 *    derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <COPYRIGHT HOLDER> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#include <boost/shared_ptr.hpp>

namespace thunk {

template<class T> class lazy_loader 
{
public:
  typedef T loader_type;

  ~lazy_loader();
  lazy_loader(); 

  template<class Y> lazy_loader(lazy_loader<Y> const& r); 

  lazy_loader& operator=(lazy_loader const& r); 
  template<class Y> lazy_loader& operator=(lazy_loader<T> const& r); 
  
  void reset(); 

  template<class Y> boost::shared_ptr<Y> object();

  template<class Y> boost::shared_ptr<Y>& operator*() const;
  template<class Y> boost::shared_ptr<T>* operator&() const;
  template<class Y> boost::shared_ptr<T>* operator->() const;
  template<class Y> boost::shared_ptr<T>* get() const;
  
private:
  boost::shared_ptr<T> m_impl;
};

lazy_loader::~lazy_loader()
{
}

lazy_loader::lazy_loader()
  : m_impl(0)
{
}

lazy_loader::lazy_loader(const lazy_loader& r)
  : m_impl(r.m_impl)
{
}

void lazy_loader::reset()
{
  if ( m_impl->get() != 0 )
    {
      m_impl->reset();
    }
}

template<typename Y>
boost::shared_ptr<Y> lazy_loader::object() 
{
  if ( m_impl.get() == 0 )
  {
    // TODO: Execute the lazy loading process here.
  }
  return m_impl;
}

template<typename Y>*
boost::shared_ptr<Y> lazy_loader::operator&()
{
  return &object();
}

template<typename Tp>&
boost::shared_ptr<Tp> lazy_loader::operator->()
{
  return *object();
}

template<typename Tp>&
boost::shared_ptr<Tp> lazy_loader::operator*()
{
  return *object();
}

} // end of thunk

#endif // LAZY_LOADER_HPP
