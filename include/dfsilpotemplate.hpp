#include <eosio/eosio.hpp>
#include <eosio/asset.hpp>
#include <eosio/singleton.hpp>

using namespace eosio;

CONTRACT dfsilpotemplate : public contract
{
public:
   using contract::contract;

   static constexpr uint64_t GENESIS_BLOCK = 1599321600;
   static constexpr name LOGIC_ACCOUNT{"defislogsone"_n};

   // 订阅 DFS LP token 变动的通知。
   [[eosio::on_notify("defislogsone::changelog")]] 
   void change(uint64_t mid, name user, asset q0, asset q1, asset bal0, asset bal1, uint64_t token);

   // 主动领取奖励
   ACTION fishing(uint64_t id, name user);

private:
   TABLE pond
   {
      uint64_t id;
      asset supply;
      asset max_supply;
      double weight;
      time_point_sec start;
      time_point_sec end;

      uint64_t primary_key() const { return id; }
   };

   TABLE miner
   {
      name miner;
      asset liq_bal0;
      asset liq_bal1;
      time_point_sec last_drip;

      uint64_t primary_key() const { return miner.value; }
   };

   typedef multi_index<"ponds"_n, pond> pond_index;
   typedef multi_index<"miners"_n, miner> miners_index;

   void join(uint64_t mid, name user);
   void claim(uint64_t mid, name user);
   void update_miner_status(uint64_t mid, name user);
   void check_liquidity_and_miner_status(uint64_t mid, name user, uint64_t token);
};