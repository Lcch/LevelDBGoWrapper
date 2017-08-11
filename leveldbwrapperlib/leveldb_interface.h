#ifndef LEVELDB_INTERFACE_H_
#define LEVELDB_INTERFACE_H_ 

#include <string>
#include "leveldb/db.h"

namespace leveldb {

class LevelDBInterface {
 public:
  LevelDBInterface();
  ~LevelDBInterface();
  
  void Put(const std::string& name, const std::string& value);
  std::string Get(const std::string& name);

 private:
  DB* db_;  
};

}  // namespace leveldb

#endif
