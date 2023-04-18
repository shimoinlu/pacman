#pragma once

struct Information
{
	Information(int L, int P, int SH)
		:m_Points(P), m_Shots(SH), m_Lives(L) {}

	int m_Lives = 0;
	int m_Points = 0;
	int m_Shots = 0;

};