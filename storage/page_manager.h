#pragma once

#include "page.h"
#include <utils/utils.h>
#include <string>
#include <list>

namespace storage {
	class PageManager : utils::NonCopy
	{
		static PageManager *m_instance;
		PageManager() = default;
	public:
		
		static void start(std::string path);
		static void stop();
		static PageManager* get();
		Page::PPage getCurPage();
		void closePage();
		void createNewPage();

		std::string getOldesPage()const;
		std::string getOldesPage(const std::list<std::string> &pages)const;
		std::string getNewPageUniqueName()const;

		std::list<std::string> pageList() const;
		void open(std::string path);
	public:
		uint64_t default_page_size;
	protected:
		std::string m_path;
		Page::PPage m_curpage;
		
	};
}