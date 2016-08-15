{
	/*
	 * Conway life

	 forAll(index,cellI)
	 {	scalar sum=0;
	 nextIndex[cellI] = 0;
	 List<int> nbrs = neighbours(mesh,cellI);
	 forAll(nbrs,nbrI)
	 {
	 sum+=index[nbrs[nbrI]];}
	 if(	((sum==2) & (index[cellI]==1))
	 || (sum==3) )

	 {	nextIndex[cellI] = 1;}
	 //Info << cellI << " " << sum << " " << index[cellI] <<endl;
	 }
	 forAll(index,cellI)
	 {
	 index[cellI]=nextIndex[cellI];
	 }
	 */

//Grain growth
	/*
	 forAll(index,cellI)
	 {
	 nextIndex[cellI] = index[cellI];
	 if(index[cellI] > 0)
	 {
	 List<int> nbrs = neighbours(mesh,cellI);
	 forAll(nbrs,nbrI)
	 {
	 if (index[nbrs[nbrI]] ==0) {nextIndex[nbrs[nbrI]]=index[cellI];}
	 }
	 }
	 }
	 */
	forAll(index,cellI)
	{
		nextIndex[cellI] = index[cellI];
		if(index[cellI] ==0) {
			List<int> nbrs = neighbours(mesh,cellI,0);
			forAll(nbrs,nbrI)
			{
				if ( (index[nbrs[nbrI]] >0)) {nextIndex[cellI]=index[nbrs[nbrI]];}
			}
		}

	}
	forAll(index,cellI)
	{
		index[cellI]=nextIndex[cellI];
	}

}
