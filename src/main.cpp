#include <iostream>
#include "dpp/dpp.h"
#include "../envars.h"

const std::string BOT_TOKEN = DISCORD_BOT_TOKEN;
const dpp::snowflake MY_GUILD_ID = DISCORD_GUILD_ID;

int main(int argc, char* argv[]){
  if(argc > 1){
    
  }
  else{
	  dpp::cluster bot(BOT_TOKEN);

	  bot.on_log(dpp::utility::cout_logger());

	  bot.on_interaction_create([](const dpp::interaction_create_t& event) {
			  if (event.command.get_command_name() == "ping"){
			  	event.reply("Pong!");
			  }
	  });

	  bot.on_ready([&bot](const dpp::ready_t& event){
			  if (dpp::run_once<struct register_bot_commands>()) {
			  	bot.guild_command_create(
					dpp::slashcommand("ping", "Ping pong!", bot.me.id),
					MY_GUILD_ID
					);
			  }
	  });

	  bot.start(false);	  
  }
   
  return 0;
}
