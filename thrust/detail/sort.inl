/*
 *  Copyright 2008-2012 NVIDIA Corporation
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 */


/*! \file sort.inl
 *  \brief Inline file for sort.h.
 */

#include <thrust/detail/config.h>
#include <thrust/sort.h>
#include <thrust/iterator/iterator_traits.h>
#include <thrust/system/detail/generic/select_system.h>
#include <thrust/system/detail/generic/sort.h>
#include <thrust/system/detail/adl/sort.h>

namespace thrust
{


template<typename System, typename RandomAccessIterator>
  void sort(thrust::detail::dispatchable_base<System> &system,
            RandomAccessIterator first,
            RandomAccessIterator last)
{
  using thrust::system::detail::generic::sort;
  return sort(system.derived(), first, last);
} // end sort()


template<typename System,
         typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void sort(thrust::detail::dispatchable_base<System> &system,
            RandomAccessIterator first,
            RandomAccessIterator last,
            StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::sort;
  return sort(system.derived(), first, last, comp);
} // end sort()


template<typename System, typename RandomAccessIterator>
  void stable_sort(thrust::detail::dispatchable_base<System> &system,
                   RandomAccessIterator first,
                   RandomAccessIterator last)
{
  using thrust::system::detail::generic::stable_sort;
  return stable_sort(system.derived(), first, last);
} // end stable_sort()


template<typename System,
         typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void stable_sort(thrust::detail::dispatchable_base<System> &system,
                   RandomAccessIterator first,
                   RandomAccessIterator last,
                   StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::stable_sort;
  return stable_sort(system.derived(), first, last, comp);
} // end stable_sort()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void sort_by_key(thrust::detail::dispatchable_base<System> &system,
                   RandomAccessIterator1 keys_first,
                   RandomAccessIterator1 keys_last,
                   RandomAccessIterator2 values_first)
{
  using thrust::system::detail::generic::sort_by_key;
  return sort_by_key(system.derived(), keys_first, keys_last, values_first);
} // end sort_by_key()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void sort_by_key(thrust::detail::dispatchable_base<System> &system,
                   RandomAccessIterator1 keys_first,
                   RandomAccessIterator1 keys_last,
                   RandomAccessIterator2 values_first,
                   StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::sort_by_key;
  return sort_by_key(system.derived(), keys_first, keys_last, values_first, comp);
} // end sort_by_key()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void stable_sort_by_key(thrust::detail::dispatchable_base<System> &system,
                          RandomAccessIterator1 keys_first,
                          RandomAccessIterator1 keys_last,
                          RandomAccessIterator2 values_first)
{
  using thrust::system::detail::generic::stable_sort_by_key;
  return stable_sort_by_key(system.derived(), keys_first, keys_last, values_first);
} // end stable_sort_by_key()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void stable_sort_by_key(thrust::detail::dispatchable_base<System> &system,
                          RandomAccessIterator1 keys_first,
                          RandomAccessIterator1 keys_last,
                          RandomAccessIterator2 values_first,
                          StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::stable_sort_by_key;
  return stable_sort_by_key(system.derived(), keys_first, keys_last, values_first, comp);
} // end stable_sort_by_key()


template<typename System, typename ForwardIterator>
  bool is_sorted(thrust::detail::dispatchable_base<System> &system,
                 ForwardIterator first,
                 ForwardIterator last)
{
  using thrust::system::detail::generic::is_sorted;
  return is_sorted(system.derived(), first, last);
} // end is_sorted()


template<typename System, typename ForwardIterator, typename Compare>
  bool is_sorted(thrust::detail::dispatchable_base<System> &system,
                 ForwardIterator first,
                 ForwardIterator last,
                 Compare comp)
{
  using thrust::system::detail::generic::is_sorted;
  return is_sorted(system.derived(), first, last, comp);
} // end is_sorted()


template<typename System, typename ForwardIterator>
  ForwardIterator is_sorted_until(thrust::detail::dispatchable_base<System> &system,
                                  ForwardIterator first,
                                  ForwardIterator last)
{
  using thrust::system::detail::generic::is_sorted_until;
  return is_sorted_until(system.derived(), first, last);
} // end is_sorted_until()


template<typename System, typename ForwardIterator, typename Compare>
  ForwardIterator is_sorted_until(thrust::detail::dispatchable_base<System> &system,
                                  ForwardIterator first,
                                  ForwardIterator last,
                                  Compare comp)
{
  using thrust::system::detail::generic::is_sorted_until;
  return is_sorted_until(system.derived(), first, last, comp);
} // end is_sorted_until()


namespace detail
{


template<typename System, typename RandomAccessIterator>
  void strip_const_sort(const System &system,
                        RandomAccessIterator first,
                        RandomAccessIterator last)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::sort(non_const_system, first, last);
} // end strip_const_sort()


template<typename System,
         typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void strip_const_sort(const System &system,
                        RandomAccessIterator first,
                        RandomAccessIterator last,
                        StrictWeakOrdering comp)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::sort(non_const_system, first, last, comp);
} // end strip_const_sort()


template<typename System, typename RandomAccessIterator>
  void strip_const_stable_sort(const System &system,
                               RandomAccessIterator first,
                               RandomAccessIterator last)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::stable_sort(non_const_system, first, last);
} // end strip_const_stable_sort()


template<typename System,
         typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void strip_const_stable_sort(const System &system,
                               RandomAccessIterator first,
                               RandomAccessIterator last,
                               StrictWeakOrdering comp)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::stable_sort(non_const_system, first, last, comp);
} // end strip_const_stable_sort()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void strip_const_sort_by_key(const System &system,
                               RandomAccessIterator1 keys_first,
                               RandomAccessIterator1 keys_last,
                               RandomAccessIterator2 values_first)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::sort_by_key(non_const_system, keys_first, keys_last, values_first);
} // end strip_const_sort_by_key()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void strip_const_sort_by_key(const System &system,
                               RandomAccessIterator1 keys_first,
                               RandomAccessIterator1 keys_last,
                               RandomAccessIterator2 values_first,
                               StrictWeakOrdering comp)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::sort_by_key(non_const_system, keys_first, keys_last, values_first, comp);
} // end strip_const_sort_by_key()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void strip_const_stable_sort_by_key(const System &system,
                                      RandomAccessIterator1 keys_first,
                                      RandomAccessIterator1 keys_last,
                                      RandomAccessIterator2 values_first)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::stable_sort_by_key(non_const_system, keys_first, keys_last, values_first);
} // end strip_const_stable_sort_by_key()


template<typename System,
         typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void strip_const_stable_sort_by_key(const System &system,
                                      RandomAccessIterator1 keys_first,
                                      RandomAccessIterator1 keys_last,
                                      RandomAccessIterator2 values_first,
                                      StrictWeakOrdering comp)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::stable_sort_by_key(non_const_system, keys_first, keys_last, values_first, comp);
} // end strip_const_stable_sort_by_key()


template<typename System, typename ForwardIterator>
  bool strip_const_is_sorted(const System &system,
                             ForwardIterator first,
                             ForwardIterator last)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::is_sorted(non_const_system, first, last);
} // end is_sorted()


template<typename System, typename ForwardIterator, typename Compare>
  bool strip_const_is_sorted(const System &system,
                             ForwardIterator first,
                             ForwardIterator last,
                             Compare comp)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::is_sorted(non_const_system, first, last, comp);
} // end is_sorted()


template<typename System, typename ForwardIterator>
  ForwardIterator strip_const_is_sorted_until(const System &system,
                                              ForwardIterator first,
                                              ForwardIterator last)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::is_sorted_until(non_const_system, first, last);
} // end is_sorted_until()


template<typename System, typename ForwardIterator, typename Compare>
  ForwardIterator strip_const_is_sorted_until(const System &system,
                                              ForwardIterator first,
                                              ForwardIterator last,
                                              Compare comp)
{
  System &non_const_system = const_cast<System&>(system);
  return thrust::is_sorted_until(non_const_system, first, last, comp);
} // end is_sorted_until()


} // end detail


///////////////
// Key Sorts //
///////////////

template<typename RandomAccessIterator>
  void sort(RandomAccessIterator first,
            RandomAccessIterator last)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator>::type System;

  System system;

  return thrust::detail::strip_const_sort(select_system(system), first, last);
} // end sort()


template<typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void sort(RandomAccessIterator first,
            RandomAccessIterator last,
            StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator>::type System;

  System system;

  return thrust::detail::strip_const_sort(select_system(system), first, last, comp);
} // end sort()


template<typename RandomAccessIterator>
  void stable_sort(RandomAccessIterator first,
                   RandomAccessIterator last)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator>::type System;

  System system;

  return thrust::detail::strip_const_stable_sort(select_system(system), first, last);
} // end stable_sort() 


template<typename RandomAccessIterator,
         typename StrictWeakOrdering>
  void stable_sort(RandomAccessIterator first,
                   RandomAccessIterator last,
                   StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator>::type System;

  System system;

  return thrust::detail::strip_const_stable_sort(select_system(system), first, last, comp);
} // end stable_sort()



/////////////////////
// Key-Value Sorts //
/////////////////////

template<typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void sort_by_key(RandomAccessIterator1 keys_first,
                   RandomAccessIterator1 keys_last,
                   RandomAccessIterator2 values_first)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator1>::type System1;
  typedef typename thrust::iterator_system<RandomAccessIterator2>::type System2;

  System1 system1;
  System2 system2;

  return thrust::detail::strip_const_sort_by_key(select_system(system1,system2), keys_first, keys_last, values_first);
} // end sort_by_key()


template<typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void sort_by_key(RandomAccessIterator1 keys_first,
                   RandomAccessIterator1 keys_last,
                   RandomAccessIterator2 values_first,
                   StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator1>::type System1;
  typedef typename thrust::iterator_system<RandomAccessIterator2>::type System2;

  System1 system1;
  System2 system2;

  return thrust::detail::strip_const_sort_by_key(select_system(system1,system2), keys_first, keys_last, values_first, comp);
} // end sort_by_key()


template<typename RandomAccessIterator1,
         typename RandomAccessIterator2>
  void stable_sort_by_key(RandomAccessIterator1 keys_first,
                          RandomAccessIterator1 keys_last,
                          RandomAccessIterator2 values_first)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator1>::type System1;
  typedef typename thrust::iterator_system<RandomAccessIterator2>::type System2;

  System1 system1;
  System2 system2;

  return thrust::detail::strip_const_stable_sort_by_key(select_system(system1,system2), keys_first, keys_last, values_first);
} // end stable_sort_by_key()


template<typename RandomAccessIterator1,
         typename RandomAccessIterator2,
         typename StrictWeakOrdering>
  void stable_sort_by_key(RandomAccessIterator1 keys_first,
                          RandomAccessIterator1 keys_last,
                          RandomAccessIterator2 values_first,
                          StrictWeakOrdering comp)
{
  using thrust::system::detail::generic::select_system;

  typedef typename thrust::iterator_system<RandomAccessIterator1>::type System1;
  typedef typename thrust::iterator_system<RandomAccessIterator2>::type System2;

  System1 system1;
  System2 system2;

  return thrust::detail::strip_const_stable_sort_by_key(select_system(system1,system2), keys_first, keys_last, values_first, comp);
} // end stable_sort_by_key()


template<typename ForwardIterator>
  bool is_sorted(ForwardIterator first,
                 ForwardIterator last)
{
  using thrust::system::detail::generic::select_system;
  
  typedef typename thrust::iterator_system<ForwardIterator>::type System;

  System system;

  return thrust::detail::strip_const_is_sorted(select_system(system), first, last);
} // end is_sorted()


template<typename ForwardIterator,
         typename Compare>
  bool is_sorted(ForwardIterator first,
                 ForwardIterator last,
                 Compare comp)
{
  using thrust::system::detail::generic::select_system;
  
  typedef typename thrust::iterator_system<ForwardIterator>::type System;

  System system;

  return thrust::detail::strip_const_is_sorted(select_system(system), first, last, comp);
} // end is_sorted()


template<typename ForwardIterator>
  ForwardIterator is_sorted_until(ForwardIterator first,
                                  ForwardIterator last)
{
  using thrust::system::detail::generic::select_system;
  
  typedef typename thrust::iterator_system<ForwardIterator>::type System;

  System system;

  return thrust::detail::strip_const_is_sorted_until(select_system(system), first, last);
} // end is_sorted_until()


template<typename ForwardIterator,
         typename Compare>
  ForwardIterator is_sorted_until(ForwardIterator first,
                                  ForwardIterator last,
                                  Compare comp)
{
  using thrust::system::detail::generic::select_system;
  
  typedef typename thrust::iterator_system<ForwardIterator>::type System;

  System system;

  return thrust::detail::strip_const_is_sorted_until(select_system(system), first, last, comp);
} // end is_sorted_until()


} // end namespace thrust

