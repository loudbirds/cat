#pragma once

#include <map>

#include <cat/functor/functor.hpp>

namespace cat
{
    // map instance:

    template <typename Fun, typename K, typename A, typename Compare, typename Alloc>
    struct FunctorInstance<std::map, Fun, K, A, Compare, Alloc> : Functor<std::map>::Class1<Fun, K, A, Compare, Alloc>
    {
        using B = decltype(std::declval<Fun>()(std::declval<A>()));

        auto fmap(Fun f, std::map<K, A, Compare, Alloc> const &xs) -> std::map<K, B, Compare, rebind_t<Alloc, std::pair<const K, B>> > final
        {
            std::map<K, B, Compare, rebind_t<Alloc, std::pair<const K, B>> > out;

            for(auto & x : xs)
                out.insert(std::make_pair(x.first, f(x.second)));

            return out;
        }
    };

} // namespace cat
