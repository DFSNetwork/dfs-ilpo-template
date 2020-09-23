#include <dfsilpotemplate.hpp>

void dfsilpotemplate::change(uint64_t mid, name user, asset q0, asset q1, asset bal0, asset bal1, uint64_t token)
{
   if (current_time_point().sec_since_epoch() <= GENESIS_BLOCK)
   {
      return;
   }

   miners_index _miners(_self, mid);
   auto m_itr = _miners.find(user.value);
   if (m_itr == _miners.end())
   {
      join(mid, user);
   }
   claim(mid, user);
   check_liquidity_and_miner_status(mid, user, token);
}

ACTION dfsilpotemplate::fishing(uint64_t id, name user)
{
   require_auth(user);
   claim(id, user);
}

void dfsilpotemplate::claim(uint64_t mid, name user)
{
   check(has_auth(LOGIC_ACCOUNT) || has_auth(_self) || has_auth(user), "claim: missing auth");

   //TODO:  claim 处理挖矿奖励逻辑

   update_miner_status(mid, user);
}

void dfsilpotemplate::join(uint64_t mid, name user)
{
   // double weight = get_weight(mid);
   // if (weight <= 0)
   //    return;
   miners_index _miners(_self, mid);
   auto miner_itr = _miners.find(user.value);
   check(miner_itr == _miners.end(), "already join");
   update_miner_status(mid, user);
}

void dfsilpotemplate::update_miner_status(uint64_t mid, name user)
{
   print(" update_miner_status: ");

   //TODO:  update_miner_status 逻辑处理
}

void dfsilpotemplate::check_liquidity_and_miner_status(uint64_t mid, name user, uint64_t token)
{
   if (token == 0)
   {
      // TODO 完全退出做市
   }
}
