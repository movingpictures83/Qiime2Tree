# Qiime2Tree
# Language: C++
# Input: QZA
# Output: PREFIX
# Tested with: PluMA 1.1, GCC 4.8.4
# Dependencies: qiime2_2021.4

Take sequences in QZA format for Qiime (Bolyen et al, 2019), 
align them, and produce phylogenetic trees (rooted and unrooted).

Four outputs will be generated, using the user-specified output prefix:
prefix_aligned_seqs.qza
prefix_aligned_masked.qza
prefix_rooted.qza
prefix_unrooted.qza
