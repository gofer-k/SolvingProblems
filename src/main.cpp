import sum_sub_array;
import search_word;
import gen_parenthesis;
import minilize_schedule_time;
import minimize_binary_operations;
import non_overlapping_intervals;
import rotation_cases;
import prefix_sums;
import nqueens;
import dyn_prog_max_sub_array;

int main() {
    ssa::test_sum_sub_array();
    sw::test_search_word();
    gp::test_generate_parenthesis();
    gp::test_valid_parentesis();
    mst::test_minilize_schedule_time();
    mso::test_minimize_binary_operations();
    noi::test_eraseOverlapIntervals();
    noi::test_intevals_intersection();
    rot_cases::test_min_element_pos_in_rotated_sorted_array();
    rot_cases::test_min_element_in_rotated_sorted_array();
    rot_cases::test_minimum_rotations_in_sorted_array();
    pfs::test_prefix_sum_contiguous_array();
    nq::testSolveNQueens();
    nq::testSolveCrossWords();
    dyn_prog::test_max_sub_array();
    return 0;
}