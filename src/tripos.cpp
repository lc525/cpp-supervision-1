#include "uni/tripos.h"

using namespace std;

namespace uni {

AcademicPlan::AcademicPlan(unsigned short year)
    : for_uni_year(year), subjects(vector<Subject>()) {}

// add function implementations for classes in include/uni/tripos.h here

bool Tripos::add_academic_plan(AcademicPlan *a) {
  //TODO for task_one
  return true;
}

} // namespace uni
