#pragma once

#include <string>
#include <memory>
#include <thread>
#include "Page.h"

namespace storage{

    const uint64_t defaultPageSize=1*1024*1024; // 1Mb

    class DataStorage{
    public:
        typedef std::shared_ptr<DataStorage> PDataStorage;
    public:
        static PDataStorage Create(const std::string& ds_path, uint64_t page_size=defaultPageSize);
        static PDataStorage Open(const std::string& ds_path);
        ~DataStorage();
        bool havePage2Write()const;

        bool append(const Meas::PMeas m);
		Meas::MeasArray readInterval(Time from, Time to);
    private:
        DataStorage();
        void createNewPage();
    protected:
        std::string m_path;
        Page::PPage m_curpage;
        uint64_t   m_default_page_size;
        std::mutex  m_write_mutex;
    };

};
