#include "fvMesh.H"
#include "HashSet.H"

List<int> neighbours(const fvMesh& mesh, const int number, const int corners) {
	List<int> result;
	if (corners == 1) {
		List<int> nbrFirst = mesh.cellCells()[number];
		List < HashSet<int> > nbrSecond;
		forAll(nbrFirst, nbrI)
		{
			nbrSecond.append(HashSet<int>(mesh.cellCells()[nbrFirst[nbrI]]));
		}
		HashSet<int> nbrConcat;
		forAll(nbrFirst, nbrI)
		{
			forAll(nbrFirst, nbrJ)
			{
				HashSet<int> nbrIsec = nbrSecond[nbrI];
				if (nbrI != nbrJ) {
					nbrIsec &= nbrSecond[nbrJ];
				} else
					nbrIsec.clear();

				nbrConcat += nbrIsec;
			}

		}
		nbrConcat += HashSet<int>(nbrFirst);
		nbrConcat.erase(number);
		result = nbrConcat.toc();
	}
	//labelList nbrSort(nbrConcat.toc());
	//sort(nbrSort);
	else
		result = mesh.cellCells()[number];
	return result;
}
