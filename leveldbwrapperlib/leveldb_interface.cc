
#include <cassert>
#include "leveldb_interface.h"

namespace leveldb {

LevelDBInterface::LevelDBInterface() {
  Options options;
  options.create_if_missing = true;
  Status status = leveldb::DB::Open(options, "/tmp/testdb", &db_);
  assert(status.ok());
}

LevelDBInterface::~LevelDBInterface() {
  delete db_;
}

void LevelDBInterface::Put(const std::string& name, const std::string& value) {
  db_->Put(WriteOptions(), name, value);
}

std::string LevelDBInterface::Get(const std::string& name) {
  std::string value;
  db_->Get(ReadOptions(), name, &value);
  return value;
}


}  // namespace leveldb
