#include <iostream>
#include <vector>
#include <string>
#include "Request.h"
#include "Response.h"

using namespace std;

class PuzzleSolver {
private:
    vector<int> lps;    // lps represents Longest Prefix Suffix vector

public:
    Response findWord(Request request) {
        lps.resize(request.getPatternSize(), 0);
        computeLPSArray(request);

        Response response = checkHorizontally(request);

        if(response.getX() != -1)
            return response;

        Response response2 = checkVertically(request);
        return response2;
    }

private:
    void computeLPSArray(Request request) {
        string pattern = request.getPattern();

        for(int i=1; i<pattern.size(); i++){
            int j = lps[i-1];

            while(j>0 && pattern[i]!=pattern[j]) {
                j = lps[j-1];
            }

            if(pattern[i]==pattern[j]) {
                j++;
            }

            lps[i] = j;
        }
    }

    Response checkHorizontally(Request request) {
        for(int i=0; i<request.getRowSize(); i++) {
            string text = "";
            for(int j=0; j<request.getColSize(); j++) {
                text += request.getPuzzleCell(i, j);
            }

            pair<int, int> xAndCountPair = searchPattern(text, request);
            if(xAndCountPair.first != -1) {
                return Response(xAndCountPair.first, i, xAndCountPair.second);
            }
        }

        return Response(-1, -1, -1);
    }

    Response checkVertically(Request request) {
        for(int j=0; j<request.getColSize(); j++) {
            string text = "";
            for(int i=0; i<request.getRowSize(); i++) {
                text += request.getPuzzleCell(i, j);
            }

            pair<int, int> yAndCountPair = searchPattern(text, request);
            if(yAndCountPair.first != -1) {
                return Response(j, yAndCountPair.first, yAndCountPair.second);
            }
        }

        return Response(-1, -1, -1);
    }

    // Here we are using KMP Algorithm with some modifications
    pair<int, int> searchPattern(string &text, Request request) {
        // i -> text
        // j -> pattern
        string pattern = request.getPattern();
        int i = 0, j = 0, m = text.size(), n = pattern.size();

        while(i < m) {
            int initialDifference;
            if(pattern[0] >= text[i-j]) {
                initialDifference = pattern[0] - text[i-j];
            } else {
                initialDifference = (26 - (text[i-j] - 'a') + (pattern[0] - 'a'));
            }

            int currentDifference;
            if(pattern[j] >= text[i]) {
                currentDifference = pattern[j] - text[i];
            } else {
                currentDifference = (26 - (text[i] - 'a') + (pattern[j] - 'a'));
            }

            if(initialDifference == currentDifference) {
                i++, j++;
            }

            // j has reached pattern.end()
            if(j==n) {
                return {i-j, initialDifference};
            }

            if(pattern[j] >= text[i]) {
                currentDifference = pattern[j] - text[i];
            } else {
                    currentDifference = (26 - (text[i] - 'a') + (pattern[j] - 'a'));
            }

            if(i<m && initialDifference != currentDifference){
                if(j!=0)
                    j = lps[j-1];
                else
                    i++;
            }
        }

        return {-1, -1};
    }
};
