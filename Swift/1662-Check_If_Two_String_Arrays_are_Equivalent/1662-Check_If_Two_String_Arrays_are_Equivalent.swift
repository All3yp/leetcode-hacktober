class Solution {
    func arrayStringsAreEqual(_ word1: [String], _ word2: [String]) -> Bool {
        let wordsSplitInChars = [word1, word2]
            .map { $0.reduce(into: "") { $0 += $1 } }
            .map { $0.map { "\($0)" } }
            .sorted { $0.count > $1.count }

        return wordsSplitInChars.reduce(nil) { r, e -> [String]? in
                ((r ?? []).isEmpty ? e : (r!.enumerated().contains { $0 >= e.count ? true : $1 != e[$0] } ? nil : r))
            } != nil
    }
}
